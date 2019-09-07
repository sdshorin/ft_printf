/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:59:00 by bjesse            #+#    #+#             */
/*   Updated: 2019/09/07 22:59:01 by bjesse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ptr_to_str(char *ptr_str, size_t ptr)
{
	size_t	mask;
	char	*ox_char;
	int		i;

	if (!ptr)
		ptr_str[0] = '0';
	i = sizeof(size_t*) * 8;
	ox_char = "0123456789abcdef";
	mask = (size_t)15;
	mask = (size_t)mask << (sizeof(size_t) * 8 - 4);
	while (i > 0)
	{
		i = i - 4;
		if (*(ptr_str - 1) != 'x' || ((mask & ptr) >> i))
			*ptr_str++ = ox_char[(size_t)(mask & ptr) >> i];
		mask = mask >> 4;
	}
}
