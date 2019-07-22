

#include "ft_printf.h"







void pass_param(char **str)
{
	(*str)++;
}

int print_param2(t_param **param, char **str, va_list ap)
{
	int print_size;

	print_size = 0;
	if ((*param)->conversion == 'd')
		print_size  = print_double(param, ap);	
	else if ((*param)->conversion == 'i')
		print_size  = print_int(param, ap);
	else if ((*param)->conversion == 'o')
		print_size  = print_o(param, ap);
	else if ((*param)->conversion == 'u')
		print_size  = print_u(param, ap);
	else if ((*param)->conversion == 'x')
		print_size  = print_x(param, ap);
	else if ((*param)->conversion == 'X')
		print_size  = print_X(param, ap);
	else if ((*param)->conversion == 'f')
		print_size  = print_float(param, ap);
	*param = (*param)->next;
	pass_param(str);
	return (print_size);
}


int print_param(t_param **param, char **str, va_list ap)
{
	int print_size;

	print_size = 0;
	if (!param || !*param)
		return (0);
	if ((*param)->conversion == 'c')
		print_size  = print_char(param, ap);
	else if ((*param)->conversion == 's')
		print_size  = print_str(param, ap);
	else if ((*param)->conversion == 'p')
		print_size  = print_ptr(param, ap);
	else
		return print_param2(param, str, ap);
	
	pass_param(str);
	*param = (*param)->next;
	return (print_size);
}

int print_string(char **str)
{
	int print_size;

	print_size = 0;
	while((*str)[print_size] && (*str)[print_size] != '%')
	{
		print_size++;
	}
	write(1, *str, print_size);
	(*str) += print_size;
	return (print_size);
}

int print_format_str(t_param *param, char *str, va_list ap)
{
	int print_size;

	print_size = 0;
	while(*str)
	{
		if (*str == '%')
			print_size += print_param(&param, &str, ap);
		else
			print_size += print_string(&str);
	}
	return print_size;
}