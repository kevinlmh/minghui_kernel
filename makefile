all: kernel

kernel: boot.o kernel.o
	i686-elf-gcc -T linker.ld -o kernel -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc

kernel.o: kernel.c
	i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

boot.o: boot.s
	i686-elf-as boot.s -o boot.o

clean:
	rm -rf *o kernel

iso:
	cp kernel isodir/boot/kernel
	grub-mkrescue -o minghui_kernel.iso isodir
