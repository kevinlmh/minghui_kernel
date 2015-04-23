# File: boot.s

# Declare constants used for creating a multiboot header.
# NOTE: We do not use MBOOT_AOUT_KLUDGE. It means that GRUB does not
# pass us a symbol table.
.set MBOOT_PAGE_ALIGN,      1<<0             # align loaded modules on page boundaries
.set MBOOT_MEM_INFO,        1<<1             # provide memory map
.set MBOOT_HEADER_FLAGS,    MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO  # this is the Multiboot 'flag' field
.set MBOOT_HEADER_MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set MBOOT_CHECKSUM,        -(MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS) # checksum of above, to prove we are multiboot

.code32                         # all instructions should be 32-bit.

# Declare a header as in the Multiboot Standard.
.section .multiboot
.global multiboot
.extern code
.extern bss
.extern end

multiboot:
    .align 4
    .long MBOOT_HEADER_MAGIC        # GRUB will search for this value on each 4-byte boundary in your kernel file
    .long MBOOT_HEADER_FLAGS        # How GRUB should load your file / settings
    .long MBOOT_CHECKSUM            # To ensure that the above values are correct

    .long multiboot                 # Location of this descriptor
    .long code                      # Start of kernel '.text' (code) section.
    .long bss                       # End of kernel '.data' section.
    .long end                       # End of kernel.
    .long start                     # Kernel entry point (initial EIP).

# The linker script specifies _start as the entry point to the kernel
# .section .text
.global start
.extern main                        # This is the entry point of our C code

# .type start, @function
start:
    # Load multiboot information:
    push %ebx

    # Execute the kernel
    cli                             # Disable interrupts.
    call kernel_main                # Call our main() function.

    # hlt
.Lhang:
    jmp .Lhang                      # Enter an infinite loop, to stop the processor
                                    # executing whatever rubbish is in the memory
                                    # after our kernel!