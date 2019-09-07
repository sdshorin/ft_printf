/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_print_nan.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:42:01 by bjesse            #+#    #+#             */
/*   Updated: 2019/09/07 22:42:02 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_nan_inf_size(t_param **param, t_long_num *num)
{
	if (num->inf && (num->sig || (*param)->space))
		return (4);
	return (3);
}

int		print_nan_inf(t_param **param, t_long_num *num)
{
	if (num->inf && (num->sig))
		ft_putchar('-');
	else if (num->inf && ((*param)->plus))
		ft_putchar('+');
	else if (num->inf && ((*param)->space))
		ft_putchar(' ');
	if (num->nan)
		ft_putstr("nan");
	else
		ft_putstr("inf");
	return (get_nan_inf_size(param, num));
}

int		put_double_nan_inf_whide(t_param **param, t_long_num *num)
{
	int len;

	len = get_nan_inf_size(param, num);
	ft_write_char_many(' ', (*param)->minimum_size - len);
	print_nan_inf(param, num);
	return (len);
}

int		print_double_nan_inf(t_param **param, t_long_num *num)
{
	int len;

	len = get_nan_inf_size(param, num);
	if ((*param)->minimum_size < len)
		return (print_nan_inf(param, num));
	if ((*param)->minus)
	{
		print_nan_inf(param, num);
		ft_write_char_many(' ', (*param)->minimum_size - len);
		return ((*param)->minimum_size);
	}
	put_double_nan_inf_whide(param, num);
	return ((*param)->minimum_size);
}
