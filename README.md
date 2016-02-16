# Minghui's Toy Kernel
A toy kernel for learning operating systems

Thanks to the following author and their tutorials:
* Brandon F. - [Bran's Kernel Development Tutorial](http://www.osdever.net/tutorials/view/brans-kernel-development-tutorial)
* OSdev.org - [Barebones](http://wiki.osdev.org/Bare_Bones) and [Meaty Skeleton](http://wiki.osdev.org/Meaty_Skeleton)

Thanks to the following websites:
* [OSdev](http://wiki.osdev.org)
* [Bona fide OS Developer](http://www.osdever.net)
* [POSIX Standard](http://pubs.opengroup.org/onlinepubs/009695399/toc.htm)
* [8259 PIC](http://stanislavs.org/helppc/8259.html)
* [Momory Management Reference](http://www.memorymanagement.org)
* [Doug Lea's malloc](http://g.oswego.edu/dl/html/malloc.html)
* [Filesystem Hierarchy Standard](http://www.pathname.com/fhs/pub/fhs-2.3.html)

## Current State
* Boots into 32-bit protected mode
* Supports basic VGA text display
	- support rainbow text output
* Global Descriptor Table(GDT) and Interrupt Descriptor Table(IDT)
* Supports Interrupt Requests
	- Has function to register interrupt handlers
* Programmable Interval Timer(PIT) enabled
* Paging enabled
* Dynamic memory allocation
* Virtual Filesystem and Initial Ramdisk

## Todos
* Extend VGA text display
	- Add video buffer and redraw function
	- Add output functions with color parameter
* Multitasking
