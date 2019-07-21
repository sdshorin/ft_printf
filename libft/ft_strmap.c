/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:46:30 by bjesse            #+#    #+#             */
/*   Updated: 2019/06/15 18:58:19 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	char	*ans;
	char	*temp;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	if (size + 1 == 0)
		return (NULL);
	ans = ft_memalloc(size + 1);
	if (!ans)
		return (NULL);
	temp = ans;
	while (size-- > 0)
		*temp++ = (*f)(*s++);
	return (ans);
}
