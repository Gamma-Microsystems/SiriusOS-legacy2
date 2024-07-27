#ifndef MEMSTUFF_H

#pragma once

#define MAX_STRING_SIZE 100

#include <stddef.h>

int is_whitespace(char c);

void strip_whitespace(char* str,char* result);

void int_to_string(int num, char *str);

void splitString(char* str, char delimiter, char** result, int* resultSize);

char* tolowercase(char* s,char* result);

char* touppercase(char* s, char* result);

#endif // MEMSTUFF_H