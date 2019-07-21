/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 21:03:39 by bjesse            #+#    #+#             */
/*   Updated: 2019/06/15 18:58:19 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*ans;
	int		size2;

	if (ft_strlen(dst) >= size)
		return (size + ft_strlen(src));
	ans = dst;
	size2 = ft_strlen(src) + ft_strlen(dst);
	while (*dst && size > 0)
	{
		size--;
		dst++;
	}
	while (*src && size > 1)
	{
		size--;
		*dst++ = *src++;
	}
	if (size > 0 || !*src)
		*dst = '\0';
	return (size2);
}
