
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
	str_size = print_with_flug(str, *param);
	return (str_size);
}


int print_ptr_with_flugs(t_param **param, char* str)
{
	int str_len;
	char fill_char;

	fill_char = ' ';
	str_len = ft_strlen(str);
	if ((*param)->minus)
	{
		write(1, str, str_len);
		ft_write_char_many(fill_char, (*param)->minimum_size - str_len);
		return ((*param)->minimum_size);
	}
	if ((*param)->zero)
		fill_char = '0';
	ft_write_char_many(fill_char, (*param)->minimum_size - str_len);
	write(1, str, str_len);
	return ((*param)->minimum_size);	
}

int print_ptr(t_param **param, va_list ap)
{
	char ptr_str[100];
	size_t ptr;
	int str_len;

	ft_memset(ptr_str, 0, 100);
	ptr = (size_t)va_arg(ap, void*);
	ptr_to_str(*(&ptr_str), ptr);
	str_len = ft_strlen(ptr_str);
	if ((*param)->minimum_size >= str_len)
		return print_ptr_with_flugs(param, ptr_str);
	write(1, ptr_str, str_len);
	return (str_len);
}