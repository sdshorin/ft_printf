
#include "ft_printf.h"


int print_with_flug(char *str, t_param *param)
{
	int str_len;
	char fill_char;

	fill_char = ' ';
	if (param->zero)
		fill_char = '0';
	str_len = ft_min(ft_strlen(str), param->precision);
	if (param->minimum_size > str_len)
		if (param->minus)
		{
			write(1, str, str_len);
			ft_write_char_many(fill_char, param->minimum_size - str_len);
		}
		else
		{
			ft_write_char_many(fill_char, param->minimum_size - str_len);
			write(1, str, str_len);
		}
	else
		write(1, str, str_len);
	
	return ();

}


int print_char(t_param **param, va_list ap)
{
	char c;

	c = va_arg(ap, char);
	write(1, &c, 1);
	return (1);
}



int  print_str(t_param **param, va_list ap)
{
	char *str;
	int str_size;

	str = va_arg(ap, char*);
	str_size = print_with_flug(str, *param);
	return (str_size);
}


int print_ptr(t_param **param, va_list ap);