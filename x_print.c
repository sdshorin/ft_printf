/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:30:23 by bjesse            #+#    #+#             */
/*   Updated: 2019/09/07 23:30:24 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_x_prenum(t_param *param, unsigned long long n)
{
	if (n == 0 && !param->ptr_shadow)
		return (0);
	if (param->hash && param->conversion == 'x')
		return (write(1, "0x", 2));
	if (param->hash && param->conversion == 'X')
		return (write(1, "0X", 2));
	return (0);
}

void	put_x_long_num(unsigned long long n, t_param *param)
{
	char *str;

	if (param->conversion == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (n < 16)
		ft_putchar(str[n]);
	else
	{
		put_x_long_num(n / 16, param);
		ft_putchar(str[n % 16]);
	}
}

void	put_x_short_num(unsigned short n, t_param *param)
{
	char *str;

	if (param->conversion == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (n < (unsigned short)16)
		ft_putchar(str[n]);
	else
	{
		put_x_short_num(n / 16, param);
		ft_putchar(str[n % 16]);
	}
}

void	put_x_char_num(unsigned char n, t_param *param)
{
	char *str;

	if (param->conversion == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (n < 16)
		ft_putchar(str[n]);
	else
	{
		put_x_char_num(n / 16, param);
		ft_putchar(str[n % 16]);
	}
}

void	write_x_num(t_param *param, unsigned long long n)
{
	int num_size;

	if (param->ptr_shadow && n == 0 && param->precision == 0)
		return ;
	num_size = ft_x_num_size(n, param);
	if (param->precision > num_size)
	{
		if (param->hash && (n || param->ptr_shadow))
			ft_write_char_many('0', param->precision - num_size + 2);
		else
			ft_write_char_many('0', param->precision - num_size);
	}
	if (param->h == 1)
		put_x_short_num(n, param);
	else if (param->h > 1)
		put_x_char_num(n, param);
	else
		put_x_long_num(n, param);
}
