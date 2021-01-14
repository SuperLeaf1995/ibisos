#ifndef VESA_H
#define VESA_H
#include <stdint.h>

struct vesa_mode_info
{
    uint32_t *framebuffer;
    uint16_t width, height;
    uint16_t pitch;
    uint16_t bpp;
} __attribute__((packed));
void init_vesa(unsigned int *multiboot_struct);
#endif