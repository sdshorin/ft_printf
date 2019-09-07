/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:13:19 by bjesse            #+#    #+#             */
/*   Updated: 2019/09/07 23:13:20 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_ptr(t_param **param, va_list ap)
{
	(*param)->conversion = 'x';
	(*param)->hash = 1;
	(*param)->l = 1;
	(*param)->ptr_shadow = 1;
	return (print_x(param, ap));
}
