#ifndef SYSTEM_H
#define SYSTEM_H
#include <stdint.h>
int inb(uint16_t port);
uint32_t inl(uint16_t port);
uint16_t inw(uint16_t port);

inline void outb(uint16_t port, uint8_t value);
void outl(uint16_t port, uint32_t value);
void outw(uint16_t port, uint16_t value);
#endif