
#include "ft_printf.h"

int put_long_double(t_param **param, t_long_num *num)
{
	int i;

	i = LONG_NUM - 1;
	if (num->sig)
		ft_putchar('-');
	while (i >= 0 && i >= num->point - 6)
	{
		if (num->num[i])
			ft_putchar(num->num[i]);
		else if (i <= num->point)
			ft_putchar('0');
		if (i == num->point)
			ft_putchar('.');
		i--;
	}

	return (42);
}