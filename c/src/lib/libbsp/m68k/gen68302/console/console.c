/*
 * Initialize the MC68302 SCC2 for console IO board support package.
 *
 *  COPYRIGHT (c) 1989, 1990, 1991, 1992, 1993, 1994.
 *  On-Line Applications Research Corporation (OAR).
 *  All rights assigned to U.S. Government, 1994.
 *
 *  This material may be reproduced by or for the U.S. Government pursuant
 *  to the copyright license under the clause at DFARS 252.227-7013.  This
 *  notice must appear in all copies of this file and its derivatives.
 *
 *  $Id$
 */

#define GEN68302_INIT

#include <rtems.h>
#include "console.h"
#include <bsp.h>

#include "m68302.h"

/*  console_initialize
 *
 *  This routine initializes the console IO driver.
 *
 *  Input parameters: NONE
 *
 *  Output parameters:  NONE
 *
 *  Return values:
 */

rtems_device_driver console_initialize(
  rtems_device_major_number  major,
  rtems_device_minor_number  minor,
  void                      *arg,
  rtems_id                   self,
  rtems_unsigned32          *status
)
{
  volatile m302_dualPortRAM_t *p = &m302;

  p->reg.pacnt |= 0x0003;		/* enable RXD2 and TXD2 signals */
  /*
   * TODO: Check assembly code.  I think gcc's volatile semantics force
   * this to not use a CLR.
   */
  p->reg.simode = 0;			/* NMSI mode */

  p->reg.scc[1].scon = 0x00d8;		/* 9600 baud */
  p->reg.scc[1].scm  = 0x01b1;

  p->scc2.parm.rfcr = 0x50;		/* Rx buffers in supervisor data */
  p->scc2.parm.tfcr = 0x50;		/* Tx buffers in supervisor data */
  p->scc2.parm.mrblr = 0x0001;		/* Max Rx buffer length is 1 byte */

  p->scc2.prot.uart.max_idl = 0x0000;	/* 0 = maximum timeout value */
  p->scc2.prot.uart.brkcr = 0x0001;	/* send 1 break char on STOP TX cmd */
  p->scc2.prot.uart.parec = 0x0000;	/* reset parity error counter */
  p->scc2.prot.uart.frmec = 0x0000;	/* reset framing error counter */
  p->scc2.prot.uart.nosec = 0x0000;	/* reset noise error counter */
  p->scc2.prot.uart.brkec = 0x0000;	/* reset break condition counter */

  p->scc2.prot.uart.character[0] = 0x0003; /* use <ctrl>c as control char */
  p->scc2.prot.uart.character[1] = 0x8000; /* set end of cntrl char table */

  p->scc2.bd.rx[0].status = 0xA000;	/* RxBD0 empty, wrap, no intr */
  p->scc2.bd.rx[0].length = 0x0000;
  p->scc2.bd.rx[0].buffer =
      (rtems_unsigned8 *) &m302.scc2.bd.rx[1]; /* RxBD1 is Rx buffer */

  p->reg.scc[1].dsr = 0x7000;		/* set full-length last stop bit */

  p->scc2.bd.tx[0].status = 0x3000;	/* TxBD0 not ready, wrap, intr */
  p->scc2.bd.tx[0].length = 0x0001;
  p->scc2.bd.tx[0].buffer =
      (rtems_unsigned8 *) &m302.scc2.bd.tx[1]; /* TxBD1 is Tx buffer */

  p->reg.scc[1].scce = 0xFF;		/* clear all SCC event flags */
  p->reg.scc[1].sccm = 0x03;		/* enable only Tx & Rx interrupts */
  p->reg.scc[1].scm  = 0x01BD;

  *status = RTEMS_SUCCESSFUL;
}


/*  is_character_ready
 *
 *  Check to see if a character is available on the MC68302's SCC2.  If so,
 *  then return a TRUE (along with the character).  Otherwise return FALSE.
 *
 *  Input parameters:   pointer to location in which to return character
 *
 *  Output parameters:  character (if available)
 *
 *  Return values:      TRUE - character available
 *                      FALSE - no character available
 */

rtems_boolean is_character_ready(
  char *ch				/* -> character  */
)
{
#define RXS (m302.scc2.bd.rx[0].status)
#define RXD (* ((volatile char *) m302.scc2.bd.rx[0].buffer))

    for (;;) {
	if (RXS & RBIT_HDLC_EMPTY_BIT)
	    return FALSE;

	*ch = RXD;
	RXS = RBIT_HDLC_EMPTY_BIT | RBIT_HDLC_WRAP_BIT;
	if ( *ch >= ' ' &&  *ch <= '~' )
	    return TRUE;
    }
}


/*  inbyte
 *
 *  Receive a character from the MC68302's SCC2.
 *
 *  Input parameters:   NONE
 *
 *  Output parameters:  NONE
 *
 *  Return values:      character read
 */

char inbyte( void )
{
    char ch;

#define RXS (m302.scc2.bd.rx[0].status)
#define RXD (* ((volatile char *) m302.scc2.bd.rx[0].buffer))

    do {
	while (RXS & RBIT_HDLC_EMPTY_BIT)
	    /* Wait until character received */ ;

	ch = RXD;
	RXS = RBIT_HDLC_EMPTY_BIT | RBIT_HDLC_WRAP_BIT;

	if (ch == '\r' || ch == '\n')
	    break;
    } while (ch < ' ' ||  ch > '~');

    return ch;
}


/*  outbyte
 *
 *  Transmit a character out on the MC68302's SCC2.
 *  It may support XON/XOFF flow control.
 *
 *  Input parameters:
 *    ch  - character to be transmitted
 *
 *  Output parameters:  NONE
 */

void outbyte(
  char ch
)
{
#define TXS (m302.scc2.bd.tx[0].status)
#define TXD (* ((volatile char *) m302.scc2.bd.tx[0].buffer))

#define RXS (m302.scc2.bd.rx[0].status)
#define RXD (* ((volatile char *) m302.scc2.bd.rx[0].buffer))

    while (TXS & RBIT_HDLC_READY_BIT)
	/* Wait until okay to transmit */ ;

    /*
     * Check for flow control requests and process.
     */
    while ( ! (RXS & RBIT_HDLC_EMPTY_BIT)) {
	if (RXD == XOFF)
	    do {
		RXS = RBIT_HDLC_EMPTY_BIT | RBIT_HDLC_WRAP_BIT;
		while (RXS & RBIT_HDLC_EMPTY_BIT)
		    /* Wait until character received */ ;
	    } while (RXD != XON);
	RXS = RBIT_HDLC_EMPTY_BIT | RBIT_HDLC_WRAP_BIT;
    }

    TXD = ch;
    TXS = RBIT_HDLC_READY_BIT | RBIT_HDLC_WRAP_BIT;
    if (ch == '\n')
	outbyte('\r');
}

/*
 * __read  -- read bytes from the serial port. Ignore fd, since
 *            we only have stdin.
 */

int __read(
  int fd,
  char *buf,
  int nbytes
)
{
  int i = 0;

  for (i = 0; i < nbytes; i++) {
    *(buf + i) = inbyte();
    if ((*(buf + i) == '\n') || (*(buf + i) == '\r')) {
      (*(buf + i++)) = '\n';
      (*(buf + i)) = 0;
      break;
    }
  }
  return (i);
}

/*
 * __write -- write bytes to the serial port. Ignore fd, since
 *            stdout and stderr are the same. Since we have no filesystem,
 *            open will only return an error.
 */

int __write(
  int fd,
  char *buf,
  int nbytes
)
{
  int i;

  for (i = 0; i < nbytes; i++) {
    if (*(buf + i) == '\n') {
      outbyte ('\r');
    }
    outbyte (*(buf + i));
  }
  return (nbytes);
}
