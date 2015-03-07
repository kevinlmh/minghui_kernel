#include <stdint.h>
#include "common.h"
#include "terminal.h"

extern void initialize_gdt();
extern void initialize_idt();

int kernel_main(struct multiboot *mboot_ptr) {
	initialize_gdt();
	initialize_idt();
	terminal_clear();
	terminal_write("Hello\tKernel\tWorld!\n");
	terminal_write_rainbow("I am a rainbow string.\n");
	asm volatile ("int $0x3");
	asm volatile ("int $0x4");
	return 0;
}
