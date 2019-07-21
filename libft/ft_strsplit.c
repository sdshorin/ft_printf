/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:43:37 by bjesse            #+#    #+#             */
/*   Updated: 2019/06/15 18:58:19 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_counter(char const *s, char c)
{
	int		counter;
	char	prev;

	counter = 0;
	prev = c;
	while (*s)
	{
		if (prev == c && *s != c)
			counter++;
		prev = *s;
		s++;
	}
	if (prev != c)
		counter++;
	return (counter);
}

static char	*copy_string(char const *s, char c)
{
	int			size;
	const char	*consttemp;
	char		*temp;
	char		*ans;

	consttemp = s;
	size = 0;
	while (*consttemp && *consttemp != c)
	{
		consttemp++;
		size++;
	}
	ans = (char*)malloc(size + 1);
	if (!ans)
		return (NULL);
	temp = ans;
	while (*s && *s != c)
		*temp++ = *s++;
	*temp = '\0';
	return (ans);
}

static char	**delete_all(char **ans)
{
	char	**temp;

	temp = ans;
	while (*temp)
		free(*temp++);
	free(ans);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	char	**ans;
	char	**temp2;

	if (!s)
		return (NULL);
	words = words_counter(s, c);
	ans = (char**)malloc((words + 1) * sizeof(char*));
	if (!ans)
		return (NULL);
	temp2 = ans;
	while (*s && words--)
	{
		while (*s && *s == c)
			s++;
		*temp2 = copy_string(s, c);
		if (!*temp2++)
			return (delete_all(ans));
		while (*s && *s != c)
			s++;
	}
	*temp2 = NULL;
	return (ans);
}
