#include "ft_printf.h"


int add_param(t_param **param, char **format)
{
	t_param *now_param;
	if (*(*format + 1) == '%')
		return (0);
	now_param = add_param_list(param);


	parse_param(*format, now_param);

	
	return (0);
}








int read_params(t_param **param, char *format)
{
	// t_param *last_param;

	while (*format)
	{
		while (*format && *format != '%')
			format++;
		if (*format == '%')
			if(add_param(param, &format))
				return (1);
	}
	return(0);
}