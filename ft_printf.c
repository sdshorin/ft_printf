/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:45:17 by bjesse            #+#    #+#             */
/*   Updated: 2019/09/07 22:45:18 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(char *format, ...)
{
	int		print_size;
	va_list	ap;
	t_param	*param;

	print_size = 0;
	param = 0;
	va_start(ap, format);
	read_params(&param, format);
	print_size = print_format_str(param, format, ap);
	delete_param(param);
	va_end(ap);
	return (print_size);
}
