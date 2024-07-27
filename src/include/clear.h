#ifndef CLEAR_H

#include <kprintf.h>

void clear() {
    for (size_t i = 0; i < NUM_ROWS; i++) {
        clear_row(i);
    }
}

#endif // CLEAR_H