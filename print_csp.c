
#include "ft_printf.h"


int print_with_flug(char *str, t_param *param)
{
	int str_len;
	char fill_char;

	fill_char = ' ';
	str_len = ft_strlen(str);
	if (param->precision >= 0)
		str_len = ft_min(str_len, param->precision);
	if (param->minimum_size >= 0 && param->minimum_size > str_len)
		if (param->minus)
		{
			write(1, str, str_len);
			ft_write_char_many(fill_char, param->minimum_size - str_len);
			return (param->minimum_size);
		}
		else
		{
			if (param->zero)
				fill_char = '0';
			ft_write_char_many(fill_char, param->minimum_size - str_len);
			write(1, str, str_len);
			return (param->minimum_size);
		}
	else
		write(1, str, str_len);
	return (str_len);
}


int print_char(t_param **param, va_list ap)
{
	char c;

	c = (char)va_arg(ap, int);
	char fill_char;

	fill_char = ' ';
	if ((*param)->minimum_size >= 1)
		if ((*param)->minus)
		{
			write(1, &c, 1);
			ft_write_char_many(fill_char, (*param)->minimum_size - 1);
			return ((*param)->minimum_size);
		}
		else
		{
			if ((*param)->zero)
				fill_char = '0';
			ft_write_char_many(fill_char, (*param)->minimum_size - 1);
			write(1, &c, 1);
			return ((*param)->minimum_size);
		}
	else
		write(1, &c, 1);
	return (1);
}



int  print_str(t_param **param, va_list ap)
{
	char *str;
	int str_size;

	str = va_arg(ap, char*);
	if (!str)
		str = "(null)";
	str_size = print_with_flug(str, *param);
	return (str_size);
}


