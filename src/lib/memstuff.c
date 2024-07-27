#include <lib.h>

int is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

void strip_whitespace(char* str, char* result) {
   
    while (*str && is_whitespace(*str)) {
        str++;
    }

    if (*str == '\0') {
        *result = '\0';
        return;
    }

   
    const char *end = str;
    while (*end) {
        end++;
    }
    end--;

    
    while (end > str && is_whitespace(*end)) {
        end--;
    }
    
    
    while (str <= end) {
        *result++ = *str++;
    }
    *result = '\0'; 
}

void reverse(char *str, int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void int_to_string(int num, char *str) {
    int i = 0;
    int isNegative = 0;
    
    if(num == 0)
    {
        strcpy(str,"0");
        return;
    }

    // Handle negative numbers
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    // Process individual digits
    while (num != 0) {
        int rem = num % 10;
        str[i++] = rem + '0';
        num = num / 10;
    }

    // Add negative sign if necessary
    if (isNegative)
        str[i++] = '-';

    // Null-terminate the string
    str[i] = '\0';

    // Reverse the string
    reverse(str, i);
}

void splitString(char* str, char delimiter, char** result, int* resultSize) {
    int index = 0;
    *resultSize = 0;

    // Handle the case where there's no delimiter in the string
    result[index++] = str;
    (*resultSize)++;

    while (*str != '\0') {
        if (*str == delimiter) {
            *str = '\0';
            result[index++] = str + 1;
            (*resultSize)++;
        }
        str++;
    }
}

char* tolowercase(char* s, char* result) {
    char* originalResult = result;

    while (*s != '\0') {
        if (*s >= 'A' && *s <= 'Z') {
            *result = *s + 32;
        } else {
            *result = *s;
        }

        ++s;
        ++result;
    }

    *result = '\0'; // Null-terminate the result string

    return originalResult;
}

char* touppercase(char* s, char* result) {
    char* originalResult = result;

    while (*s != '\0') {
        if (*s >= 'a' && *s <= 'z') {
            *result = *s - 32;
        } else {
            *result = *s;
        }

        ++s;
        ++result;
    }

    *result = '\0'; // Null-terminate the result string

    return originalResult;
}