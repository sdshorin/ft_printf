/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:30:17 by bjesse            #+#    #+#             */
/*   Updated: 2019/09/07 23:30:19 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_x_num_size(unsigned long long num, t_param *param)
{
	int size;

	size = 0;
	if (num == (unsigned long long)-1 && param->h == 1)
		return (4);
	if (num == (unsigned long long)-1 && param->h == 2)
		return (2);
	if (num == 0 && (!param->ptr_shadow || param->precision != 0))
		size++;
	if (param->hash && (num != 0 || param->ptr_shadow))
		size += 2;
	while (num > 0)
	{
		size++;
		num /= 16;
	}
	return (size);
}

int		print_x_zero(t_param *param)
{
	ft_write_char_many(' ', param->minimum_size);
	return (ft_max(param->minimum_size, 0));
}

int		print_x_with_whide(t_param **param, unsigned long long n, int num_size)
{
	if ((*param)->minus)
	{
		write_x_prenum(*param, n);
		write_x_num(*param, n);
		ft_write_char_many(' ', (*param)->minimum_size - num_size);
	}
	else
	{
		if ((*param)->zero && (*param)->precision == -1)
		{
			write_x_prenum(*param, n);
			ft_write_char_many('0', (*param)->minimum_size - num_size);
			write_x_num(*param, n);
		}
		else
		{
			ft_write_char_many(' ', (*param)->minimum_size - num_size);
			write_x_prenum(*param, n);
			write_x_num(*param, n);
		}
	}
	return ((*param)->minimum_size);
}

int		print_x(t_param **param, va_list ap)
{
	unsigned long long		n;
	int						num_size;

	n = 0;
	if ((*param)->l == 0 && (*param)->h == 0)
		n = (unsigned long long)va_arg(ap, unsigned int);
	else if ((*param)->l == 1)
		n = (unsigned long long)va_arg(ap, unsigned long);
	else if ((*param)->l > 1)
		n = (unsigned long long)va_arg(ap, unsigned long long);
	else if ((*param)->h == 1)
		n = (unsigned long long)(short)va_arg(ap, unsigned int);
	else if ((*param)->h > 1)
		n = (unsigned long long)(unsigned char)va_arg(ap, unsigned int);
	num_size = ft_max((*param)->precision, ft_x_num_size(n, *param));
	if (num_size == (*param)->precision && (*param)->hash && (n || \
	(*param)->ptr_shadow))
		num_size += 2;
	if ((*param)->precision == 0 && n == 0 && !(*param)->ptr_shadow)
		return (print_x_zero(*param));
	if ((*param)->minimum_size >= num_size)
		return (print_x_with_whide(param, n, num_size));
	write_x_prenum(*param, n);
	write_x_num(*param, n);
	return (num_size);
}
