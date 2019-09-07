

#include "ft_printf.h"

int ft_x_num_size(unsigned long long num, t_param *param)
{
	int size = 0;
	
	if (num == 0)
		size++;
	if (param->hash && num != 0)
		size += 2;
	while (num > 0)
	{
		size++;
		num /= 16;
	}
	return (size);
}



int print_x_zero(t_param *param)
{
	ft_write_char_many(' ', param->minimum_size);
	return (ft_max(param->minimum_size, 0));
}

int print_x_with_whide(t_param **param, unsigned long long n, int num_size)
{	
	if ((*param)->minus)
	{
		write_x_prenum(*param, n);
		write_x_num(*param, n);
		ft_write_char_many(' ', (*param)->minimum_size  - num_size);
	}
	else
	{
		if ((*param)->zero && (*param)->precision == -1)
		{
			write_x_prenum(*param, n);
			ft_write_char_many('0', (*param)->minimum_size  - num_size);
			write_x_num(*param, n);
		}
		else
		{
			ft_write_char_many(' ', (*param)->minimum_size  - num_size);
			write_x_prenum(*param, n);
			write_x_num(*param, n);
		}
	}
	return ((*param)->minimum_size);
}

int print_x(t_param **param, va_list ap)
{
	unsigned long long n;
	int num_size;

	if ((*param)->l == 0 && (*param)->h == 0)
		n = (unsigned long long)va_arg(ap, unsigned int);
	if ((*param)->l == 1)
		n = (unsigned long long)va_arg(ap, unsigned long);
	if ((*param)->l > 1)
		n = (unsigned long long)va_arg(ap, unsigned long long);
	if ((*param)->h == 1)
		n = (unsigned long long)(short)va_arg(ap, unsigned int);
	if ((*param)->h > 1)
		n = (unsigned long long)(unsigned char)va_arg(ap, unsigned int);
	num_size = ft_max((*param)->precision, ft_x_num_size(n, *param));
	if ((*param)->precision == 0 && n == 0)
		return print_x_zero(*param);
	if ((*param)->minimum_size >= num_size)
		return (print_x_with_whide(param, n, num_size));
	write_x_prenum(*param, n);
	write_x_num(*param, n);
	return(num_size);
}
