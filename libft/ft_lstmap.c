/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 21:42:07 by bjesse            #+#    #+#             */
/*   Updated: 2019/06/15 18:58:19 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ans;
	t_list	*temp;

	if (!lst || !f)
		return (NULL);
	ans = (*f)(lst);
	lst = lst->next;
	temp = ans;
	while (temp && lst)
	{
		temp->next = (*f)(lst);
		temp = temp->next;
		lst = lst->next;
	}
	if (!temp)
		return (NULL);
	return (ans);
}
