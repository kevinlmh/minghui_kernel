#ifndef __SYSTEM_H
#define __SYSTEM_H

/* system.c */
void *memcpy(void *dest, const void *src, size_t count);
void *memset(void *dest, int8_t val, size_t count);
uint16_t *memsetw(uint16_t *dest, uint16_t val, size_t count);
size_t strlen(const int8_t *str);
uint8_t inportb(uint16_t _port);
void outportb (uint16_t _port, uint8_t _data);

#endif
