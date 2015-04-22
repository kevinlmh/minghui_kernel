#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>
#include <stddef.h>

/* common.c */
void *memcpy(void *dest, const void *src, size_t count);
void *memset(void *dest, uint8_t val, size_t count);
uint16_t *memsetw(uint16_t *dest, uint16_t val, size_t count);
size_t strlen(const char *str);
int strcmp(char *str1, char *str2);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);

uint8_t inb(uint16_t _port);
uint16_t inw(uint16_t _port);
void outb(uint16_t _port, uint8_t _data);
void outw(uint16_t _port, uint16_t _data);

#define PANIC(msg) panic(msg, __FILE__, __LINE__);
#define ASSERT(b) ((b) ? (void)0 : panic_assert(__FILE__, __LINE__, #b))

extern void panic(const char *message, const char *file, uint32_t line);
extern void panic_assert(const char *file, uint32_t line, const char *desc);

#endif
