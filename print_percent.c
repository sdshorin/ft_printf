/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:29:07 by bjesse            #+#    #+#             */
/*   Updated: 2019/09/07 23:29:09 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_percent(t_param **param)
{
	if ((*param)->minus)
		ft_putchar('%');
	if ((*param)->minimum_size > 0 && (*param)->zero)
		ft_write_char_many('0', (*param)->minimum_size - 1);
	if ((*param)->minimum_size > 0 && !(*param)->zero)
		ft_write_char_many(' ', (*param)->minimum_size - 1);
	if (!(*param)->minus)
		ft_putchar('%');
	if ((*param)->minimum_size > 0)
		return ((*param)->minimum_size);
	return (1);
}
