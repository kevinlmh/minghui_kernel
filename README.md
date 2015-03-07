# Minghui Kernel
A toy kernel for learning operating systems

Thanks to the following author and their tutorials:
* Brandon F. - [Bran's Kernel Development Tutorial](http://www.osdever.net/tutorials/view/brans-kernel-development-tutorial)
* OSdev.org - [Barebones](http://wiki.osdev.org/Bare_Bones) and [Meaty Skeleton](http://wiki.osdev.org/Meaty_Skeleton)
* James Molloy - [JamesM's Kernel Development Tutorials](http://www.jamesmolloy.co.uk/tutorial_html/index.html)

Thanks to the following websites:
* [OSdev](http://wiki.osdev.org)
* [Bona fide OS Developer](http://www.osdever.net)
* [POSIX Standard](http://pubs.opengroup.org/onlinepubs/009695399/toc.htm)

## Current State
* Boots into 32bit protected mode
* Supports basic VGA text display
	- support rainbow text output

## Todos
### Extend VGA text display
* Add video buffer and redraw function
* Add output functions with color parameter
### Setup GDT and IDT
