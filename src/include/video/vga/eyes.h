#ifndef EYES_H

#include <video/vga/colors.h>
#include <video/tty/defs.h>
#include <video/vga/vga_wh.h>

void eyes(void) 
{
	row = 0;
	column = 0;
	color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	buffer = (uint16_t*) 0xB8000; // Video start
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			buffer[index] = vga_entry(' ', color);
		}
	}
}

#endif // EYES_H