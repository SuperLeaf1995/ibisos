#ifndef DISPLAY_H
#define DISPLAY_H
#include <malloc/malloc.h>
#include <stdint.h>

struct VbeInfoBlock
{
    char VbeSignature[4];
    uint16_t VbeVersion;
    uint16_t OemStringPtr[2];
} __attribute__ ((packed));

#endif