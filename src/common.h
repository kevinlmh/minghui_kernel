#ifndef SYSTEM_H
#define SYSTEM_H

#include <stddef.h>

/* common.c */
void *memcpy(void *dest, const void *src, size_t count);
void *memset(void *dest, int8_t val, size_t count);
uint16_t *memsetw(uint16_t *dest, uint16_t val, size_t count);
size_t strlen(const int8_t *str);

uint8_t inb(uint16_t _port);
uint16_t inw(uint16_t _port);
void outb(uint16_t _port, uint8_t _data);
void outw(uint16_t _port, uint16_t _data);

#endif
