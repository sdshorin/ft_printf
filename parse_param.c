/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:27:17 by bjesse            #+#    #+#             */
/*   Updated: 2019/09/07 23:27:18 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*parse_param_flags(char *format, t_param *now_param)
{
	while (*format && ft_findchar(" +-0#", *format))
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
	if (now_param->minus)
		now_param->zero = 0;
	return (format);
}

char	*parse_param_width(char *input_string, t_param *now_param)
{
	if (ft_isdigit(*input_string))
		now_param->minimum_size = ft_atoi(input_string);
	while (ft_isdigit(*input_string))
		input_string++;
	return (input_string);
}

char	*parse_param_precision(char *input_string, t_param *now_param)
{
	if (*input_string == '.')
	{
		input_string++;
		now_param->precision = ft_atoi(input_string);
		while (ft_isdigit(*input_string))
			input_string++;
	}
	return (input_string);
}

char	*parse_param_size(char *input_string, t_param *now_param)
{
	int h_counter;
	int l_counter;
	int ll_counter;

	h_counter = 0;
	l_counter = 0;
	ll_counter = 0;
	while (ft_findchar("hlL", *input_string))
	{
		if (*input_string == 'h' && !l_counter)
			h_counter++;
		if (*input_string == 'l' && !h_counter)
			l_counter++;
		if (*input_string == 'L')
			ll_counter++;
		input_string++;
	}
	now_param->h = h_counter;
	now_param->l = l_counter;
	now_param->ll = ll_counter;
	return (input_string);
}

char	*parse_param_type(char *input_string, t_param *now_param)
{
	if (ft_findchar("%cspdiouxXf", *input_string))
	{
		now_param->conversion = *input_string;
		input_string++;
	}
	return (input_string);
}
