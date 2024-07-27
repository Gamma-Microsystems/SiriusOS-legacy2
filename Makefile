ARCH = x86_64
CC = $(ARCH)-sirius-gcc
LD = $(ARCH)-sirius-ld
AS = nasm

kernel_source_files := $(shell find src/ -name *.c)
kernel_object_files := $(patsubst src/%.c, build/%.o, $(kernel_source_files))

x86_64_asm_source_files := $(shell find src/arch/x86_64 -name *.asm)
x86_64_asm_object_files := $(patsubst src/arch/x86_64/%.asm, build/x86_64/%.o, $(x86_64_asm_source_files))

x86_64_object_files := $(x86_64_asm_object_files)

.PHONY: clean
clean:
	rm -rf dist/ build/ ports-build/

.PHONY: build-x86_64
build-x86_64: $(kernel_object_files)
	$(kernel_object_files): build/kernel/%.o : src/%.c
		mkdir -p $(dir $@) && \
		$(CC) -c -I src/include -ffreestanding $(patsubst build/%.o, src/%.c, $@) -o $@

	$(x86_64_asm_object_files): build/x86_64/%.o : src/arch/x86_64/%.asm
		mkdir -p $(dir $@) && \
		$(AS) -f elf64 $(patsubst build/x86_64/%.o, src/arch/x86_64/%.asm, $@) -o $@

	mkdir -p dist/x86_64 && \
	$(LD) -n -o dist/x86_64/sirius.bin -T ld/link.ld $(kernel_object_files) && \
	cp dist/x86_64/sirius.bin sysroot/boot/sirius.bin && \
	$(ROOTCMD) dd if=/dev/zero of=SiriusOS bs=1M count=38
	mkfs -t fat SiriusOS