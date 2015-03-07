//
// isr.c -- High level interrupt service routines and interrupt request handlers.
// Part of this code is modified from JamesM's kernel development tutorials.
//

#include "common.h"
#include "isr.h"
#include "terminal.h"

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers_t regs) {
	terminal_write("recieved interrupt: ");
	terminal_write_dec(regs.int_no);
	terminal_put('\t');
	terminal_write_dec(regs.err_code);
	terminal_put('\n');
} 