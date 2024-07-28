bin = sirius.bin
sources := arch/i686/boot.s sys/main.c
ARCH = i686
TRIPLET = elf
CC = $(ARCH)-$(TRIPLET)-gcc
LD = $(ARCH)-$(TRIPLET)-ld
AS = $(ARCH)-$(TRIPLET)-as

clean:
    @rm config.status configure config.log
    @rm Makefile
    @rm -r autom4te.cache/
    @rm aclocal.m4
    @rm compile install-sh missing Makefile.in
