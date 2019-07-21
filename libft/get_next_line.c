/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjesse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 21:18:38 by bjesse            #+#    #+#             */
/*   Updated: 2019/06/15 18:58:19 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fd_list	*new_t_fd_list(int fd)
{
	t_fd_list	*temp;

	temp = (t_fd_list*)malloc(sizeof(t_fd_list));
	temp->fd = fd;
	temp->str = ft_strnew(0);
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

static int			del_list(t_fd_list **temp, t_fd_list **start_list)
{
	t_fd_list *next;

	if (*temp == *start_list)
		*start_list = NULL;
	next = (*temp)->next;
	if ((*temp)->prev)
		(*temp)->prev->next = (*temp)->next;
	if ((*temp)->next)
		(*temp)->next->prev = (*temp)->prev;
	free((*temp)->str);
	free(*temp);
	*temp = next;
	return (-1);
}

static t_fd_list	*find_t_fd_list(const int fd, t_fd_list **start_list)
{
	t_fd_list			*temp;

	temp = *start_list;
	if (!*start_list)
		*start_list = new_t_fd_list(fd);
	temp = *start_list;
	while (temp->next && temp->fd != fd)
		temp = temp->next;
	if (!(temp->fd == fd))
	{
		temp->next = new_t_fd_list(fd);
		temp->next->prev = temp;
		temp = temp->next;
	}
	return (temp);
}

static int			read_to_list(t_fd_list *temp, t_fd_list **start_list)
{
	char			buff[BUFF_SIZE + 1];
	char			*temp_str;
	int				ch_read;

	ft_memset(buff, '\0', BUFF_SIZE);
	while ((ch_read = read(temp->fd, buff, BUFF_SIZE)))
	{
		if (ch_read < 0)
			return (del_list(&temp, start_list));
		buff[ch_read] = '\0';
		temp_str = ft_strjoin(temp->str, buff);
		free(temp->str);
		temp->str = temp_str;
		if (!temp_str)
			return (del_list(&temp, start_list));
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	t_fd_list			*temp;
	char				*temp_str;
	char				*ptr;
	static t_fd_list	*start_list;

	ptr = NULL;
	if (fd < 0 || !line)
		return (-1);
	temp = find_t_fd_list(fd, &start_list);
	if (read_to_list(temp, &start_list) == -1)
		return (-1);
	if (!(*temp->str))
		return (del_list(&temp, &start_list) + 1);
	temp_str = temp->str;
	if ((ptr = ft_strchr(temp_str, '\n')))
	{
		*ptr = '\0';
		temp->str = ft_strdup(ptr + 1);
	}
	else
		temp->str = ft_strdup("\0");
	if (*temp_str || ptr)
		*line = ft_strdup(temp_str);
	free(temp_str);
	return (1);
}
