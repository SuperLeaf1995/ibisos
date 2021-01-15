#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <vesa/vesa.h>
void draw_first_quad_arc(uint32_t *buffer, int x_center, int y_center, int r, uint32_t color);
void draw_circle(uint32_t* buffer, int x_center, int y_center, int r, uint32_t color);
#endif