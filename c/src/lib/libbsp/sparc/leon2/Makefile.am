ACLOCAL_AMFLAGS = -I ../../../../aclocal

include $(top_srcdir)/../../../../automake/compile.am
include $(top_srcdir)/../../bsp.am

dist_project_lib_DATA = ../../../../../../bsps/sparc/leon2/start/bsp_specs


noinst_PROGRAMS =


start.$(OBJEXT): ../../../../../../bsps/sparc/shared/start/start.S
	$(CPPASCOMPILE) -o $@ -c $<
project_lib_DATA = start.$(OBJEXT)

project_lib_DATA += linkcmds
dist_project_lib_DATA += ../../../../../../bsps/sparc/shared/start/linkcmds.base
dist_project_lib_DATA += ../../../../../../bsps/sparc/leon2/start/linkcmds.at697f
dist_project_lib_DATA += ../../../../../../bsps/sparc/leon2/start/linkcmds.leon2

project_lib_LIBRARIES = librtemsbsp.a
librtemsbsp_a_SOURCES =

# startup
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/start/bspfatal-default.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/start/bspreset-empty.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/leon2/start/bspstart.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/start/bspgetworkarea.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/dev/getentropy/getentropy-cpucounter.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/start/sbrk.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/leon2/start/setvec.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/leon2/start/spurious.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/leon2/start/bspidle.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/leon2/start/bspdelay.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/start/bsp_fatal_exit.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/start/bsp_fatal_halt.c

# gnatsupp
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/leon2/gnatsupp/gnatsupp.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/gnatcommon.c
# console
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/leon2/console/console.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/leon2/console/debugputs.c
# clock
librtemsbsp_a_SOURCES +=../../../../../../bsps/sparc/leon2/clock/ckinit.c
# IRQ
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/irq/genirq.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/irq/irq-shared.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/irq/bsp_isr_handler.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/irq/irq-default-handler.c

# AMBA bus
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/amba/ambapp.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/amba/ambapp_alloc.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/amba/ambapp_count.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/amba/ambapp_depth.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/amba/ambapp_find_by_idx.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/amba/ambapp_freq.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/amba/ambapp_parent.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/amba/ambapp_old.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/amba/ambapp_names.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/amba/ambapp_show.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/amba/ahbstat.c

# Clock Driver and Timer Library
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/btimer/gptimer.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/btimer/tlib.c

# PCI
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/pci/grpci2.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/pci/grpci2dma.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/pci/grpci.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/pci/pcif.c
librtemsbsp_a_SOURCES +=  ../../../../../../bsps/sparc/shared/pci/pci_memreg_sparc_le.c
librtemsbsp_a_SOURCES +=  ../../../../../../bsps/sparc/shared/pci/pci_memreg_sparc_be.c
librtemsbsp_a_SOURCES +=  ../../../../../../bsps/sparc/leon2/pci/at697_pci.c

# PCI target devices
librtemsbsp_a_SOURCES +=  ../../../../../../bsps/sparc/shared/pci/gr_701.c
librtemsbsp_a_SOURCES +=  ../../../../../../bsps/sparc/shared/pci/gr_rasta_adcdac.c
librtemsbsp_a_SOURCES +=  ../../../../../../bsps/sparc/shared/pci/gr_rasta_io.c
librtemsbsp_a_SOURCES +=  ../../../../../../bsps/sparc/shared/pci/gr_rasta_spw_router.c
librtemsbsp_a_SOURCES +=  ../../../../../../bsps/sparc/shared/pci/gr_rasta_tmtc.c
librtemsbsp_a_SOURCES +=  ../../../../../../bsps/sparc/shared/pci/gr_leon4_n2x.c
librtemsbsp_a_SOURCES +=  ../../../../../../bsps/sparc/shared/pci/gr_cpci_gr740.c

# B1553BRM
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/1553/b1553brm.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/1553/b1553rt.c

# GR1553B
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/1553/gr1553b.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/1553/gr1553bc.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/1553/gr1553bm.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/1553/gr1553rt.c

# CAN
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/can/occan.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/can/grcan.c

# SpaceWire
if !HAS_SMP
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/spw/grspw.c
endif
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/spw/grspw_pkt.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/spw/grspw_router.c

# UART (RAW)
# I2CMST
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/i2c/i2cmst.c

# SPI
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/spi/spictrl.c

# TIME
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/time/spwcuc.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/time/grctm.c

# GPIO
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/gpio/grgpio.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/gpio/gpiolib.c

# PWM
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/pwm/grpwm.c

# ADC and DAC
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/analog/gradcdac.c

# Memory controllers
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/mem/mctrl.c
# l2cache
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/l2c/l2c.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/leon2/start/cache.c
# griommu
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/iommu/griommu.c
# timer
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/leon2/btimer/btimer.c

# TM/TC
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/tmtc/grtc.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/tmtc/grtm.c

# MEMSCRUB
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/scrub/memscrub.c
# L4STAT
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/stat/l4stat.c

# Driver Manager
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/drvmgr/ambapp_bus.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/drvmgr/ambapp_bus_leon2.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/drvmgr/leon2_amba_bus.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/drvmgr/get_resarray_count.c

if HAS_SMP
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/start/bspsmp-dummy.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/shared/start/getcurrentprocessor-zero.c
endif

if HAS_NETWORKING
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/leon2/net/leon_smc91111.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/leon2/net/leon_open_eth.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/net/greth.c
librtemsbsp_a_SOURCES += ../../../../../../bsps/sparc/shared/net/network_interface_add.c
endif


include $(top_srcdir)/../../../../automake/local.am
include $(srcdir)/../../../../../../bsps/shared/irq-sources.am
include $(srcdir)/../../../../../../bsps/shared/shared-sources.am
include $(srcdir)/../../../../../../bsps/sparc/leon2/headers.am
