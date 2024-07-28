#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <video/vga/colors.h>
#include <video/vga/eyes.h>
#include <compile/stop.h>
#include <video/tty/tty.h>z

void kmain(void) 
{
    eyes();
	/* Initialize terminal interface */
	init_tty();

	kwrite_str("Hello, kernel World!\n");
}