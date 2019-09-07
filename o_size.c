
#include "ft_printf.h"
int ft_o_num_size_h(unsigned short num, t_param *param)
{
	int size = 0;
	
	if (num == (unsigned short)-1)
			return (6);
	if (param->hash && num != 0)
		size++;
	if (num == 0)
		size++;
	while (num > 0)
	{
		size++;
		num /= 8;
	}
	return (size);
}

int ft_o_num_size_hh(unsigned char num, t_param *param)
{
	int size = 0;
	
	if (num == (unsigned char)-1)
			return (3);
	if (param->hash && num != 0)
		size++;
	if (num == 0)
		size++;
	while (num > 0)
	{
		size++;
		num /= 8;
	}
	return (size);
}