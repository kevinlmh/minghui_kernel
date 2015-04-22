/* File: system.c
 * Author: Minghui Liu
 *
 * Modified based on Brandon F.'s code in Bran's Kernel Development Tutorial
 */

#include <stdint.h>
#include "common.h"

// Copy count bytes from src to dest.
void *memcpy(void *dest, const void *src, size_t count) {
	const uint8_t *sp = (const uint8_t *)src;
	uint8_t *dp = (uint8_t *)dest;
	for (; count != 0; count--) 
		*dp++ = *sp++;
	return dest;
}

// Write count copies of val into dest.
void *memset(void *dest, uint8_t val, size_t count) {
	uint8_t *temp = (uint8_t *)dest;
	for (; count != 0; count--)
		*temp++ = val;
	return dest;
}

// Write count copies of val into dest.
uint16_t *memsetw(uint16_t *dest, uint16_t val, size_t count) {
	uint16_t *temp = (uint16_t *)dest;
	for (; count != 0; count--)
		*temp++ = val;
	return dest;
}

size_t strlen(const char *str) {
	size_t retval;
	for (retval = 0; *str != '\0'; str++)
		retval++;
	return retval;
}

// Compare two strings. Should return -1 if 
// str1 < str2, 0 if they are equal or 1 otherwise.
int strcmp(char *str1, char *str2) {
      int i = 0;
      int failed = 0;
      while(str1[i] != '\0' && str2[i] != '\0') {
          if(str1[i] != str2[i]) {
              failed = 1;
              break;
          }
          i++;
      }
      // why did the loop exit?
      if( (str1[i] == '\0' && str2[i] != '\0') || (str1[i] != '\0' && str2[i] == '\0') )
          failed = 1;
  
      return failed;
}

// Copy the NULL-terminated string src into dest, and
// return dest.
char *strcpy(char *dest, const char *src) {
    do {
      *dest++ = *src++;
    }
    while (*src != 0);
    return dest;
}

// Concatenate the NULL-terminated string src onto
// the end of dest, and return dest.
char *strcat(char *dest, const char *src) {
    while (*dest != 0) {
        dest++;
    }

    do {
        *dest++ = *src++;
    }
    while (*src != 0);
    return dest;
}

uint8_t inb(uint16_t _port) {
	uint8_t ret;
	__asm__ __volatile__ ("inb %1, %0" : "=a" (ret) : "dN" (_port));
	return ret;
}

void outb(uint16_t _port, uint8_t _data) {
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

uint16_t inw(uint16_t _port) {
	uint16_t ret;
	__asm__ __volatile__ ("inw %1, %0" : "=a" (ret) : "dN" (_port));
	return ret;
}

void outw(uint16_t _port, uint16_t _data) {
	__asm__ __volatile__ ("outw %1, %0" : : "dN" (_port), "a" (_data));
}

extern void panic(const char *message, const char *file, uint32_t line)
{
    // We encountered a massive problem and have to stop.
    asm volatile("cli"); // Disable interrupts.

    terminal_write("PANIC(");
    terminal_write(message);
    terminal_write(") at ");
    terminal_write(file);
    terminal_write(":");
    terminal_write_dec(line);
    terminal_write("\n");
    // Halt by going into an infinite loop.
    for(;;);
}

extern void panic_assert(const char *file, uint32_t line, const char *desc)
{
    // An assertion failed, and we have to panic.
    asm volatile("cli"); // Disable interrupts.

    terminal_write("ASSERTION-FAILED(");
    terminal_write(desc);
    terminal_write(") at ");
    terminal_write(file);
    terminal_write(":");
    terminal_write_dec(line);
    terminal_write("\n");
    // Halt by going into an infinite loop.
    for(;;);
}
