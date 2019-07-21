/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 22:21:49 by bjesse            #+#    #+#             */
/*   Updated: 2019/06/15 18:58:19 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*temph;
	const char	*tempn;

	if (!*haystack && *needle)
		return (NULL);
	if (!*needle)
		return ((char*)(void*)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			temph = haystack;
			tempn = needle;
			while (*tempn && *temph && *temph == *tempn)
			{
				temph++;
				tempn++;
			}
			if (*tempn == '\0')
				return ((char*)(void*)haystack);
		}
		haystack++;
	}
	return (NULL);
}
