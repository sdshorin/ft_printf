

#include <stdarg.h>
#include "ft_printf.h"

// va_arg(ap, char *);



void printf(char *format, ...)
{
	int print_size;
	va_list ap;
	t_param *param;

	print_size = 0;
	va_start(ap, format);
	read_params(&param, format);
	print_format_str(param, format, ap);
	delete_param(param);
	va_end(ap);
	return (print_size);
}











