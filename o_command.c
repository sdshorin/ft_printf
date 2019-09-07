/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:06:40 by bjesse            #+#    #+#             */
/*   Updated: 2019/09/07 23:06:41 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_o_num_size(unsigned long long num, t_param *param)
{
	int size;

	size = 0;
	if (param->h == 1)
		return (ft_o_num_size_h(num, param));
	if (param->h == 2)
		return (ft_o_num_size_hh(num, param));
	if (param->hash && (num != 0 || param->precision > 0))
		size++;
	if (num == 0)
		size++;
	while (num > 0)
	{
		size++;
		num /= 8;
	}
	return (size);
}

int		print_o_zero(t_param *param)
{
	int is_prenum;

	if (param->minus)
	{
		is_prenum = write_o_prenum(param);
		ft_write_char_many(' ', param->minimum_size - is_prenum);
	}
	else
	{
		if (param->hash)
			is_prenum = 1;
		else
			is_prenum = 0;
		ft_write_char_many(' ', param->minimum_size - is_prenum);
		write_o_prenum(param);
	}
	return (ft_max(param->minimum_size, is_prenum));
}

int		print_o_with_whide(t_param **param, unsigned long long n, int num_size)
{
	if ((*param)->minus)
	{
		write_o_prenum(*param);
		write_o_num(*param, n);
		ft_write_char_many(' ', (*param)->minimum_size - num_size);
	}
	else
	{
		if ((*param)->zero && (*param)->precision == -1)
		{
			write_o_prenum(*param);
			ft_write_char_many('0', (*param)->minimum_size - num_size);
			write_o_num(*param, n);
		}
		else
		{
			ft_write_char_many(' ', (*param)->minimum_size - num_size);
			write_o_prenum(*param);
			write_o_num(*param, n);
		}
	}
	return ((*param)->minimum_size);
}

int		print_o(t_param **param, va_list ap)
{
	unsigned long long	n;
	int					num_size;

	if ((*param)->l == 0 && (*param)->h == 0)
		n = (unsigned long long)va_arg(ap, unsigned int);
	else if ((*param)->l == 1)
		n = (unsigned long long)va_arg(ap, unsigned long);
	else if ((*param)->l > 1)
		n = (unsigned long long)va_arg(ap, unsigned long long);
	else if ((*param)->h == 1)
		n = (unsigned long long)(short)va_arg(ap, unsigned int);
	else
		n = (unsigned long long)(unsigned char)va_arg(ap, unsigned int);
	num_size = ft_max((*param)->precision, ft_o_num_size(n, *param));
	if ((*param)->precision == 0 && n == 0)
		return (print_o_zero(*param));
	if ((*param)->minimum_size >= num_size)
		return (print_o_with_whide(param, n, num_size));
	write_o_prenum(*param);
	write_o_num(*param, n);
	return (num_size);
}
