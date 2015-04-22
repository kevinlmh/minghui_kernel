#include <stdint.h>
#include "common.h"
#include "terminal.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"

int kernel_main(struct multiboot *mboot_ptr) {
	initialize_gdt();
	initialize_idt();
	terminal_clear();
	terminal_write("Hello\tKernel\tWorld!\n");
	terminal_write_rainbow("I am a rainbow string.\n");
	
	// asm volatile ("int $0x3");
	// asm volatile ("int $0x4");
 	asm volatile("sti");
    init_timer(50);
    terminal_write("[DEBUG]:outside init_timer()\n");

    // uint32_t *ptr = (uint32_t*)0xA0000000;
    // uint32_t do_page_fault = *ptr;

	return 0;
}
