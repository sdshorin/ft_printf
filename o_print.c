/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:10:58 by bjesse            #+#    #+#             */
/*   Updated: 2019/09/07 23:11:00 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_o_prenum(t_param *param)
{
	if (param->hash)
		return (write(1, "0", 1));
	return (0);
}

void	put_o_long_num(unsigned long long n)
{
	if (n < 8)
		ft_putchar('0' + n);
	else
	{
		put_o_long_num(n / 8);
		ft_putchar('0' + (n % 8));
	}
}

void	put_o_short_num(unsigned short n)
{
	if (n < 8)
		ft_putchar('0' + n);
	else
	{
		put_o_short_num(n / 8);
		ft_putchar('0' + (n % 8));
	}
}

void	put_o_char_num(unsigned char n)
{
	if (n < 8)
		ft_putchar('0' + n);
	else
	{
		put_o_char_num(n / 8);
		ft_putchar('0' + (n % 8));
	}
}

void	write_o_num(t_param *param, unsigned long long n)
{
	int num_size;

	if (n == 0 && param->hash && param->precision < 1)
		return ;
	num_size = ft_o_num_size(n, param);
	if (param->precision > num_size)
		ft_write_char_many('0', param->precision - num_size);
	if (param->h == 1)
		put_o_short_num(n);
	else if (param->h > 1)
		put_o_char_num(n);
	else
		put_o_long_num(n);
}
