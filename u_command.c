

#include "ft_printf.h"

int ft_u_num_size(unsigned long long num)
{
	int size = 0;
	
	if (num == 0)
		return (1);
	while (num > 0)
	{
		size++;
		num /= 10;
	}
	return (size);
}



int print_u_zero(t_param *param)
{
		ft_write_char_many(' ', param->minimum_size);
	return (ft_max(0, param->minimum_size));
}

int print_u_with_whide(t_param **param, unsigned long long n, int num_size)
{	
	if ((*param)->minus)
	{
		write_u_num(*param, n);
		ft_write_char_many(' ', (*param)->minimum_size  - num_size);
	}
	else
	{
		if ((*param)->zero && (*param)->precision == -1)
		{
			ft_write_char_many('0', (*param)->minimum_size  - num_size);
			write_u_num(*param, n);
		}
		else
		{
			ft_write_char_many(' ', (*param)->minimum_size  - num_size);
			write_u_num(*param, n);
		}
	}
	return ((*param)->minimum_size);
}

int print_u(t_param **param, va_list ap)
{
	long long n;
	int num_size;

	if ((*param)->l == 0 && (*param)->h == 0)
		n = (unsigned long long)va_arg(ap, unsigned int);
	if ((*param)->l == 1)
		n = (unsigned long long)va_arg(ap, unsigned long);
	if ((*param)->l > 1)
		n = (unsigned long long)va_arg(ap, unsigned long long);
	if ((*param)->h == 1)
		n = (unsigned long long)(unsigned short)va_arg(ap, unsigned int);
	if ((*param)->h > 1)
		n = (unsigned long long)(unsigned char)va_arg(ap, unsigned int);
	num_size = 0;
	num_size += ft_max((*param)->precision, ft_u_num_size(n));
	if ((*param)->precision == 0 && n == 0)
		return print_u_zero(*param);
	if ((*param)->minimum_size >= num_size)
		return (print_u_with_whide(param, n, num_size));
	write_u_num(*param, n);
	return(num_size);
}
