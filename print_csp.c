
#include "ft_printf.h"






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
	str_size = ft_strlen(str);
	write(1, str, str_size);
	return (str_size);
}


int print_ptr(t_param **param, va_list ap);