bin = sirius.bin
ARCH = x86_64
sources := arch/$(ARCH)/header.asm arch/$(ARCH)/main.asm arch/$(ARCH)/main64.asm sys/main.c lib/syscall.c lib/mm/pmm.c lib/mm/vmm.c
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
