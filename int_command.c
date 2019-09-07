

#include "ft_printf.h"

int ft_num_size(long long num)
{
	int size = 0;
	
	if (num == 0)
		size++;
	if (num > 0)
		num = -num;
	while (num < 0)
	{
		size++;
		num /= 10;
	}
	return (size);
}



int print_int_zero(t_param *param)
{
	int is_prenum;
	if (param->minus)
	{
		is_prenum = write_prenum(param, 0);
		ft_write_char_many(' ', param->minimum_size  - is_prenum);
	}
	else
	{
		if (param->space || param->plus)
			is_prenum = 1;
		else
			is_prenum = 0;
		ft_write_char_many(' ', param->minimum_size  - is_prenum);
		write_prenum(param, 0);
	}
	return (ft_max(param->minimum_size, is_prenum));
}

int print_int_with_whide(t_param **param, long long n, int num_size)
{	
	if ((*param)->minus)
	{
		write_prenum(*param, n);
		write_num(*param, n);
		ft_write_char_many(' ', (*param)->minimum_size  - num_size);
	}
	else
	{
		if ((*param)->zero && (*param)->precision == -1)
		{
			write_prenum(*param, n);
			ft_write_char_many('0', (*param)->minimum_size  - num_size);
			write_num(*param, n);
		}
		else
		{
			ft_write_char_many(' ', (*param)->minimum_size  - num_size);
			write_prenum(*param, n);
			write_num(*param, n);
		}
	}
	return ((*param)->minimum_size);
}

int print_int(t_param **param, va_list ap)
{
	long long n;
	int num_size;

	if ((*param)->l == 0 && (*param)->h == 0)
		n = (long long)va_arg(ap, int);
	else if ((*param)->l == 1)
		n = (long long)va_arg(ap, long);
	else if ((*param)->l > 1)
		n = (long long)va_arg(ap, long long);
	else if ((*param)->h == 1)
		n = (long long)(short)va_arg(ap, int);
	else //if ((*param)->h > 1)
		n = (long long)(char)va_arg(ap, int);
	num_size = 0;
	if ((*param)->plus || (*param)->space || n < 0)
		num_size = 1;
	num_size += ft_max((*param)->precision, ft_num_size(n));
	if ((*param)->precision == 0 && n == 0)
		return print_int_zero(*param);
	if ((*param)->minimum_size >= num_size)
		return (print_int_with_whide(param, n, num_size));
	write_prenum(*param, n);
	write_num(*param, n);
	return(num_size);
}
