ACLOCAL_AMFLAGS = -I ../../aclocal

bin_PROGRAMS = cklength eolstrip packhex unhex rtems-bin2c

cklength_SOURCES = cklength.c
eolstrip_SOURCES = eolstrip.c compat.c
packhex_SOURCES = packhex.c
unhex_SOURCES = unhex.c compat.c
rtems_bin2c_SOURCES = rtems-bin2c.c compat.c

bin_SCRIPTS = install-if-change

noinst_SCRIPTS = multigen cvsignore-add.sh

noinst_SCRIPTS += doxy-filter

include $(top_srcdir)/../../automake/host.am
