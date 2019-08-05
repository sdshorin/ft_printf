#include "ft_printf.h"







int add_param(t_param **param, char **format)
{
	t_param *now_param;
	char *input_string;

	(*format)++;
	if (*(*format) == '%')
		return (0);
	now_param = new_param_list();
	if (!now_param)
		return (1);
	if (*param)
		(*param)->next = now_param;
	*param = now_param;
	input_string = parse_param_flags(*format, now_param);
	input_string = parse_param_width(input_string, now_param);
	input_string = parse_param_precision(input_string, now_param);
	input_string = parse_param_size(input_string, now_param);
	input_string = parse_param_type(input_string, now_param);
	*format = input_string;
	return (0);
}



int read_params(t_param **param, char *format)
{
	t_param *last_param;

	last_param = 0;
	while (*format)
	{
		while (*format && *format != '%')
			format++;
		if (*format == '%')
		{
			if(add_param(&last_param, &format))
				return (1);
			if (!*param)
				*param = last_param;
		}
	}
	return(0);
}