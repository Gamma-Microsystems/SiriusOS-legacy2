#include <kputs.h>
#include <clear.h>
#include <colors.h>

void kmain() {
    clear();
    color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    kprintf("Hello, World!");
}