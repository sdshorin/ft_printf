

#include "ft_printf.h"





int write_prenum(t_param *param, long long n)
{
	if (n < 0)
		return (write(1, "-", 1));
	if (param->space)
		return (write(1, " ", 1));
	if (param->plus)
		return (write(1, "+", 1));
	return (0);
}


void put_long_num(long long n)
{
	if (n < -10)
		ft_putchar('0' - n);
	else
	{
		put_long_num(n / 10);
		ft_putchar('0' - ( n % 10));
	}
}


void write_num(t_param *param, long long n)
{
	int num_size;

	num_size = ft_num_size(n);
	if (param->precision > num_size)
		ft_write_char_many('0',param->precision - num_size);
	if (n < 0)
		n = -n;
	put_long_num(n);
}
