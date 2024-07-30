#ifndef STRLEN_H
#define STRLEN_H 1

size_t strlen(const char* str) 
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

#endif // STRLEN_H