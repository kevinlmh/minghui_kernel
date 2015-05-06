CC=i686-elf-gcc
AS=i686-elf-as
LD=i686-elf-ld
CFLAGS=-m32 -ffreestanding -nostdlib -fno-builtin -fno-stack-protector -Wall -Wextra

# IDIR=../include	# include directory
# LDIR=../lib		# library directory
# ODIR=obj		# objects directory
# LIBS=-lgcc		# libraries

# C source files
CSOURCES=kernel.c common.c monitor.c descriptor_tables.c isr.c timer.c \
		 kheap.c paging.c ordered_array.c fs.c initrd.c test.c
# Assembly source files
SSOURCES=boot.s gdt.s interrupt.s

# Object files
OBJECTS=$(CSOURCES:.c=.o) $(SSOURCES:.s=.o)
# OBJECTS=$(patsubst %,$(ODIR)/%,$(_OBJECTS))

all: kernel

kernel: $(OBJECTS)
	$(LD) -T link.ld -o $@ $^

.s.o:
	$(AS) -o $@ $^

interrupt.o: interrupt.s
	nasm -felf $<

clean:
	rm -rf *.o kernel

initrd:
	../make_initrd ../test.txt test.txt ../test2.txt test2.txt
	mv initrd.img ../initrd.img

iso:
	cp kernel ../isodir/boot/kernel
	cp ../initrd.img ../isodir/boot/initrd
	grub-mkrescue -d /usr/lib/grub/i386-pc -o ../minghui_kernel.iso ../isodir

qemu:
	qemu-system-i386 ../minghui_kernel.iso

test: kernel initrd iso qemu
