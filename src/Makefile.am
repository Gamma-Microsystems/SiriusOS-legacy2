bin = sirius
ARCH = x86_64
TRIPLET = sirius
CFLAGS := -Iinclude -ffreestanding -Os
ASFLAGS := -f elf64
CC = $(ARCH)-$(TRIPLET)-gcc
LD = $(ARCH)-$(TRIPLET)-ld
AS = nasm
VER = 0.01

$(kernel_object_files): build/kernel/%.o : src/%.c
	mkdir -p $(dir $@) && \
	$(CC) -c $(CFLAGS) $(patsubst build/%.o, src/%.c, $@) -o $@

$(x86_64_asm_object_files): build/x86_64/%.o : arch/x86_64/%.asm
	mkdir -p $(dir $@) && \
	$(AS) $(ASFLAGS) $(patsubst build/x86_64/%.o, src/arch/x86_64/%.asm, $@) -o $@

clean:
	@rm config.status configure config.log
	@rm Makefile
	@rm -r autom4te.cache/
	@rm aclocal.m4
	@rm compile install-sh missing Makefile.in
	@rm -rf dist/ build/

build-x86_64: $(x86_64_asm_object_files) $(kernel_object_files)
	$(LD) -n -o dist/x86_64/sirius -T ld/link.ld $(kernel_object_files) && \
	cp dist/x86_64/sirius ../sysroot/boot/sirius && \
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/x86_64/SiriusOS-$(VER).iso ../sysroot