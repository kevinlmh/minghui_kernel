# Minghui Kernel
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

## Current State
* Boots into 32-bit protected mode
* Supports basic VGA text display
	- support rainbow text output
* Has Global Descriptor Table(GDT) and Interrupt Descriptor Table(IDT)
* Supports Interrupt Requests
	- Has function to register interrupt handlers
* Has Programmable Interval Timer(PIT)
* Paging is enabled
* Dynamic memory allocation

## Todos
* Extend VGA text display
	- Add video buffer and redraw function
	- Add output functions with color parameter
* File System
* Multitasking
