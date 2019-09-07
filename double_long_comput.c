/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_long_comput.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:39:45 by bjesse            #+#    #+#             */
/*   Updated: 2019/09/07 22:39:46 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	long_comput_add_dig(char *num, int exp, int d)
{
	while (exp < LONG_NUM)
	{
		if (num[exp] + d > '9')
		{
			num[exp] = num[exp] + d - 10;
			exp++;
			d = 1;
		}
		else
		{
			if (num[exp] >= '0')
				num[exp] += d;
			else
				num[exp] = '0' + d;
			break ;
		}
	}
}

void	long_comput_div_two(t_long_num *num)
{
	int in_memory;
	int temp_in_memory;
	int i;

	in_memory = 0;
	i = 0;
	while (i < LONG_NUM && (in_memory || num->num[i]))
	{
		if (!num->num[i])
			num->num[i] = '0';
		temp_in_memory = ((num->num[i] - '0') * 5 + in_memory) / 10;
		num->num[i] = '0' + ((num->num[i] - '0') * 5 + in_memory) % 10;
		in_memory = temp_in_memory;
		i++;
	}
	if (num->num[0])
		num->point++;
}

void	long_comput_mult_two(t_long_num *num)
{
	int in_memory;
	int temp_in_memory;
	int i;

	in_memory = 0;
	i = 0;
	while (i < LONG_NUM && (in_memory || num->num[i]))
	{
		if (!num->num[i])
			num->num[i] = '0';
		temp_in_memory = ((num->num[i] - '0') * 2 + in_memory) / 10;
		num->num[i] = '0' + ((num->num[i] - '0') * 2 + in_memory) % 10;
		in_memory = temp_in_memory;
		i++;
	}
}
