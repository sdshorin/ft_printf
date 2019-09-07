/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_size.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:12:08 by bjesse            #+#    #+#             */
/*   Updated: 2019/09/07 23:12:10 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_o_num_size_h(unsigned short num, t_param *param)
{
	int size;

	size = 0;
	if (num == (unsigned short)-1)
		return (6);
	if (param->hash && num != 0)
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

int		ft_o_num_size_hh(unsigned char num, t_param *param)
{
	int size;

	size = 0;
	if (num == (unsigned char)-1)
		return (3);
	if (param->hash && num != 0)
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
