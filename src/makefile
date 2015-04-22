CC=i686-elf-gcc
AS=i686-elf-as
LD=i686-elf-ld
CFLAGS=-m32 -ffreestanding -nostdlib -fno-builtin -fno-stack-protector -Wall -Wextra

# IDIR=../include	# include directory
# LDIR=../lib		# library directory
# ODIR=obj		# objects directory
# LIBS=-lgcc		# libraries

# C source files
CSOURCES=kernel.c common.c terminal.c gdt.c idt.c isr.c timer.c kheap.c paging.c
# Assembly source files
SSOURCES=boot.s gdt_asm.s idt_asm.s interrupts.s

# Object files
OBJECTS=$(CSOURCES:.c=.o) $(SSOURCES:.s=.o)
# OBJECTS=$(patsubst %,$(ODIR)/%,$(_OBJECTS))

all: kernel

kernel: $(OBJECTS)
	$(LD) -T link.ld -o $@ $^

.s.o:
	$(AS) -o $@ $^

interrupts.o: interrupts.s
	nasm -felf $<

clean:
	rm -rf *.o kernel

iso:
	cp kernel ../isodir/boot/kernel
	grub-mkrescue -d /usr/lib/grub/i386-pc -o ../minghui_kernel.iso ../isodir

qemu:
	qemu-system-i386 ../minghui_kernel.iso

test: kernel iso qemu
