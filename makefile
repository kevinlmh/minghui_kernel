CC=i686-elf-gcc
CFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra

all: kernel

kernel: boot.o kernel.o system.o
	$(CC) -T linker.ld -o kernel -ffreestanding -O2 -nostdlib boot.o system.o kernel.o -lgcc

kernel.o: kernel.c
	$(CC) $(CFLAGS) -c kernel.c -o kernel.o

system.o: system.c
	$(CC) $(CFLAGS) -c system.c -o system.o

boot.o: boot.s
	i686-elf-as boot.s -o boot.o

clean:
	rm -rf *o kernel

iso:
	cp kernel isodir/boot/kernel
	grub-mkrescue -o minghui_kernel.iso isodir
