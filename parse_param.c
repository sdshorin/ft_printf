#include "ft_printf.h"

char *parse_param_flags(char *format, t_param *now_param)
{
	while (*format && ft_findchar(" +-0#"))
	{
		if (*format == ' ')
			now_param->space = 1;
		else if (*format == '+')
			now_param->plus = 1;
		else if (*format == '-')
			now_param->minus = 1;
		else if (*format == '#')
			now_param->hash = 1;
		else if (*format == '0')
			now_param->zero = 1;
		format++;
	}
	return (format);
}




	input_string = parse_param_width(input_string, now_param);
	input_string = parse_param_precision(input_string, now_param);
	input_string = parse_param_size(input_string, now_param);
	input_string = parse_param_type(input_string, now_param);

