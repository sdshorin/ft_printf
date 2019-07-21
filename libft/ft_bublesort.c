/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bublesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 21:48:46 by bjesse            #+#    #+#             */
/*   Updated: 2019/06/15 18:58:19 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bublesort(void **data, size_t size, size_t step,
		int (*compare)(void*, void*))
{
	size_t	i;
	size_t	j;
	void	*temp;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size - 1)
		{
			if ((*compare)(data[j * step], data[(j + 1) * step]) < 0)
			{
				temp = data[j * step];
				data[j * step] = data[(j + 1) * step];
				data[(j + 1) * step] = temp;
			}
			j++;
		}
		i++;
	}
}
