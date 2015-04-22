//
// isr.c -- High level interrupt service routines and interrupt request handlers.
// Part of this code is modified from JamesM's kernel development tutorials.
//

#include "common.h"
#include "isr.h"
#include "terminal.h"

isr_t interrupt_handlers[256];

void register_interrupt_handler(uint8_t n, isr_t handler) {
    terminal_write("[DEBUG]:inside register_interrupt_handler(), n=");
    terminal_write_dec(n);
    terminal_write(", handler=");
    terminal_write_hex(handler);
    interrupt_handlers[n] = handler;
    terminal_write(", interrupt_handlers[n]=");
    terminal_write_hex(interrupt_handlers[n]);
    terminal_write("\n");
}

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers_t regs) {
	terminal_write("recieved interrupt: ");
	terminal_write_hex(regs.int_no);
	terminal_put('\t');
	terminal_write_hex(regs.err_code);
	terminal_put('\n');

	if (interrupt_handlers[regs.int_no] != 0) {
        isr_t handler = interrupt_handlers[regs.int_no];
        handler(regs);
    }
} 

// This gets called from our ASM interrupt handler stub.
void irq_handler(registers_t regs) {
    terminal_write("recieved irq: ");
    terminal_write_hex(regs.int_no);
    terminal_put('\t');
    terminal_write_hex(regs.err_code);
    terminal_put('\n');
    
    // Send an EOI (end of interrupt) signal to the PICs.
    // If this interrupt involved the slave.
    if (regs.int_no >= 40)
    {
        // Send reset signal to slave.
        outb(0xA0, 0x20);
    }
    // Send reset signal to master. (As well as slave, if necessary).
    outb(0x20, 0x20);

    if (interrupt_handlers[regs.int_no] != 0)
    {
        isr_t handler = interrupt_handlers[regs.int_no];
        handler(regs);
    }
}