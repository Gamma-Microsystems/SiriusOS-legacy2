#ifndef TTY_H
#define TTY_H 1

#include <NotSoLibc/strlen.h>
#include <video/vga/vga_wh.h>

void kputchar(char c) 
{
	kputentryat(c, color, column, row);
	if (++column == VGA_WIDTH) {
		column = 0;
		if (++row == VGA_HEIGHT)
			row = 0;
	}
}

void kwrite(const char* data, size_t size) 
{
	for (size_t i = 0; i < size; i++)
		kputchar(data[i]);
}

void kwrite_str(const char* data) 
{
	kwrite(data, strlen(data));
}

void kputentryat(char c, uint8_t color, size_t x, size_t y) 
{
	const size_t index = y * VGA_WIDTH + x;
	buffer[index] = vga_entry(c, color);
}

#endif // TTY_H