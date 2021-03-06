/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:29:56 by bjesse            #+#    #+#             */
/*   Updated: 2019/09/07 23:30:05 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_u_long_num(unsigned long long n)
{
	if (n < 10)
		ft_putchar('0' + n);
	else
	{
		put_u_long_num(n / 10);
		ft_putchar('0' + (n % 10));
	}
}

void	write_u_num(t_param *param, unsigned long long n)
{
	int num_size;

	num_size = ft_u_num_size(n);
	if (param->precision > num_size)
		ft_write_char_many('0', param->precision - num_size);
	put_u_long_num(n);
}
