# Declare constants used for creating a multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

.code32							# all instructions should be 32-bit.

# Declare a header as in the Multiboot Standard.
.section .multiboot
.global multiboot
multiboot:
	.align 4
	.long MAGIC
	.long FLAGS
	.long CHECKSUM

# .long multiboot               # Location of this descriptor
#    .long code                    # Start of kernel '.text' (code) section.
#    .long bss                     # End of kernel '.data' section.
#    .long end                     # End of kernel.
#    .long _start                   # Kernel entry point (initial EIP).

# Create a temporary stack
.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

# The linker script specifies _start as the entry point to the kernel
.section .text
.global start

.type start, @function
start:
	# Our stack (as it grows downwards).
	movl $stack_top, %esp
	
	# Load multiboot information:
    push %ebx
	call kernel_main

	cli
	hlt
.Lhang:
	jmp .Lhang

# This is useful when debugging or when you implement call tracing.
.size start, . - start
