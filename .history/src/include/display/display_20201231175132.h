#ifndef DISPLAY_H
#define DISPLAY_H
#include <malloc/malloc.h>
#include <stdint.h>

struct VbeInfoBlock
{
    char VbeSignature[4];
    uint16_t VbeVersion;
    uint16_t OemStringPtr[2];
    uint8_t Capabilities[4];
    uint16_t VideoModePtr[2];
    uint16_t TotalMemory;
} __attribute__ ((packed));

struct VbeInfoBlock* block = (struct VbeInfoBlock*) malloc(512);

#endif