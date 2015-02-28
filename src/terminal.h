/* terminal.h -- Defines the interface for terminal.h
 * Author: Minghui Liu
 * modified based on JamesM's kernel development tutorials.
 */

#ifndef TERMINAL_H
#define TERMINAL_H

#include "common.h"

// Write a single character out to the screen.
void terminal_put(char c);

// Clear the screen to all black.
void terminal_clear();

// Output a null-terminated ASCII string to the monitor.
void terminal_write(char *c);

// Output a hex value to the monitor.
void terminal_write_hex(uint32_t n);

// Output a decimal value to the monitor.
void terminal_write_dec(uint32_t n);

#endif // TERMINAL_H