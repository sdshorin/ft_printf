/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:00:01 by bjesse            #+#    #+#             */
/*   Updated: 2019/06/15 18:58:19 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	space_counter(char const *s)
{
	int		space_num;
	int		now_space;
	int		is_start;

	is_start = 1;
	space_num = 0;
	now_space = 0;
	while (*s)
	{
		if (*s == ' ' || *s == '\n' || *s == '\t')
			now_space++;
		else
		{
			if (is_start)
				space_num += now_space;
			now_space = 0;
			is_start = 0;
		}
		s++;
	}
	return (space_num + now_space);
}

char		*ft_strtrim(char const *s)
{
	int		len;
	char	*ans;
	char	*temp;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - space_counter(s);
	ans = (char*)malloc(len + 1);
	if (!ans)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	temp = ans;
	while (len--)
		*temp++ = *s++;
	*temp = '\0';
	return (ans);
}
