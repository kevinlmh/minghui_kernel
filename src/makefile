CC=i686-elf-gcc
AS=i686-elf-as
CFLAGS=-std=gnu99 -ffreestanding -O2 -nostdlib -Wall -Wextra

IDIR=../include	# include directory
LDIR=../lib		# library directory
ODIR=obj		# objects directory
LIBS=-lgcc		# libraries

# C source files
CSOURCES=kernel.c common.c terminal.c
# Assembly source files
SSOURCES=boot.s

# object files
OBJECTS=$(CSOURCES:.c=.o) $(SSOURCES:.s=.o)
# OBJECTS=$(patsubst %,$(ODIR)/%,$(_OBJECTS))

all: kernel

kernel: $(OBJECTS)
	$(CC) -T linker.ld -o $@ $^ $(CFLAGS)
 
%.o: %.c
	$(CC) -c -o $@ $^ $(CFLAGS)

%.o: %.s
	$(AS) -o $@ $^

clean:
	rm -rf *.o kernel

iso:
	cp kernel ../isodir/boot/kernel
	grub-mkrescue -o minghui_kernel.iso isodir
