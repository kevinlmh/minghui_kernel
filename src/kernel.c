/*
 * File: main.c
 * Defines the C-code kernel entry point, calls initialisation routines.
 */

#include "monitor.h"
#include "descriptor_tables.h"
#include "timer.h"

int kernel_main(struct multiboot *mboot_ptr) {
    // Initialise all the ISRs and segmentation
    init_descriptor_tables();
    // Initialise the screen (by clearing it)
    monitor_clear();
    // Write out a sample string
    monitor_write("Hello, world!\n");

    // Test interrupts
    // asm volatile("int $0x3");
    // asm volatile("int $0x4");

    // Test PIT
    // asm volatile("sti");
    // init_timer(50);

    // Test paging
    uint32_t *ptr = (uint32_t*)0xA0000000;
    uint32_t do_page_fault = *ptr;

    return 0;
}
