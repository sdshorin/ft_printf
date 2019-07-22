
#include "libft.h"


void ft_write_char_many(char filler, int size)
{
	while (size)
	{
		write(1, &filler, 1);
		size--;
	}
}