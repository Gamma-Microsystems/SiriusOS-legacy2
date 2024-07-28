#ifndef STRLEN_H

size_t strlen(const char* str) 
{
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}

#endif // STRLEN_H