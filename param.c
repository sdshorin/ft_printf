#include "ft_printf.h"


int add_param(t_param *param);


int read_params(t_param **param, char *format)
{
	t_param *last_param;

	while (*format)
	{
		while (*format && *format != '%')
			format++;
		if (*format == '%')
			format = add_param(param)

}