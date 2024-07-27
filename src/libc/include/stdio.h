#ifndef _STDIO_H
#define _STDIO_H 1

#include "sys/cdefs.h"

#define EOF (-1)

#ifdef __cplusplus
extern "C" {
#endif

void kputs()
void kpchar(char character)
void kprintf(char* str)

#ifdef __cplusplus
}
#endif

#endif
