/* File: system.c
 * Author: Minghui Liu
 *
 * Modified based on Brandon F.'s code in Bran's Kernel Development Tutorial
 */

#include <stdint.h>
#include "system.h"

void *memcpy(void *dest, const void *src, size_t count) {
	const int8_t *sp = (const int8_t *)src;
	int8_t *dp = (int8_t *)dest;
	for (; count != 0; count--) 
		*dp++ = *sp++;
	return dest;
}

void *memset(void *dest, int8_t val, size_t count) {
	int8_t *temp = (int8_t *)dest;
	for (; count != 0; count--)
		*temp++ = val;
	return dest;
}

uint16_t *memsetw(uint16_t *dest, uint16_t val, size_t count) {
	uint16_t *temp = (uint16_t *)dest;
	for (; count != 0; count--)
		*temp++ = val;
	return dest;
}

size_t strlen(const int8_t *str) {
	size_t retval;
	for (retval = 0; *str != '\0'; str++)
		retval++;
	return retval;
}

uint8_t inportb(uint16_t _port) {
	uint8_t rv;
	__asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
	return rv;
}

void outportb (uint16_t _port, uint8_t _data) {
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}