/* File: system.c
 * Author: Minghui Liu
 *
 * Modified based on Brandon F.'s code in Bran's Kernel Development Tutorial
 */

#include <stdint.h>
#include "common.h"

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