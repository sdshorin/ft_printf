
#include "ft_printf.h"


int print_ptr(t_param **param, va_list ap)
{
	(*param)->conversion = 'x';
	(*param)->hash = 1;
	(*param)->l = 1;
	(*param)->ptr_shadow = 1;

	return (print_x(param, ap));
}