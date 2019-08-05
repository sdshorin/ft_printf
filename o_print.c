

#include "ft_printf.h"





int write_o_prenum(t_param *param)
{
	if (param->hash)
		return (write(1, "0", 1));
	return (0);
}


void put_o_long_num(unsigned long long n)
{
	if (n < 8)
		ft_putchar('0' + n);
	else
	{
		put_o_long_num(n / 8);
		ft_putchar('0' + ( n % 8));
	}
}


void write_o_num(t_param *param, unsigned long long n)
{
	int num_size;

	if (n == 0 && param->hash)
		return ;
	num_size = ft_o_num_size(n, param);
	if (param->precision > num_size)
		ft_write_char_many('0',param->precision - num_size);
	put_o_long_num(n);
}
