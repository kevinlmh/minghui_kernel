/* terminal.h -- Defines the interface for terminal.h
 * Author: Minghui Liu
 * modified based on JamesM's kernel development tutorials.
 */

#ifndef TERMINAL_H
#define TERMINAL_H

#include "common.h"

/* Hardware text mode color constants. */
enum terminal_colors {
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GREY = 7,
	COLOR_DARK_GREY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_LIGHT_BROWN = 14,
	COLOR_WHITE = 15
};

// Terminal color type.
typedef uint8_t terminal_color_t; // currently unused

// Write a single character out to the screen with specified color
void terminal_put_color(char c, terminal_color_t foreColor, terminal_color_t backColor);

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

// Output a null-terminated ASCII string to the monitor with random color for each char
void terminal_write_rainbow(const char *str);

#endif // TERMINAL_H