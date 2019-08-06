
#include "ft_printf.h"




int print_float(t_param **param, va_list ap)
{

	char c;
	char l = (*param)->zero;
	l = 0;
	c = (char)va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}
