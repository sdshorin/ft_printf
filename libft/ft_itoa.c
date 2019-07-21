/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 21:17:47 by bjesse            #+#    #+#             */
/*   Updated: 2019/06/15 18:58:19 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	answer_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len += 1;
	while (n)
	{
		len += 1;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*ans;
	long	num;

	len = answer_len(n);
	ans = (char*)malloc(len + 1);
	if (!ans)
		return (NULL);
	ans[len] = '\0';
	if (n == 0)
		ans[0] = '0';
	num = n;
	if (n < 0)
		num = -(long)n;
	while (num && len--)
	{
		ans[len] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*ans = '-';
	return (ans);
}
