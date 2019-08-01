#include "ft_printf.h"

void ptr_to_str(char *ptr_str, size_t ptr)
{
	size_t mask;
	char *ox_char;
	int i;

	i = sizeof(size_t*)*8;
	ox_char = "0123456789abcdef";
	mask = (size_t)15;
	*ptr_str++ = '0';
	*ptr_str++ = 'x';
	mask  = (size_t) mask << (sizeof(size_t)*8 - 4);
	while (i > 0)
	{
		i = i - 4;
		if (*(ptr_str - 1) != 'x' || ((mask & ptr) >> i))
			*ptr_str++ = ox_char[(size_t)(mask & ptr) >> i];
		mask = mask >> 4;
	}
}