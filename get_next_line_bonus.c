/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvong <kvong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:15:22 by kvong             #+#    #+#             */
/*   Updated: 2021/08/10 16:47:28 by kvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	delete_gnl(t_gnl **gnl, int fd)
{
	t_gnl	*tmp;
	t_gnl	*next;
	t_gnl	*previous;

	tmp = *gnl;
	previous = NULL;
	while (tmp)
	{
		if (tmp->fd == fd)
			break ;
		previous = tmp;
		tmp = tmp->next;
	}
	if (tmp)
	{
		next = tmp->next;
		free(tmp);
		if (!previous)
			*gnl = next;
		else
			previous->next = next;
	}
}

static t_gnl	*ret_gnl(t_gnl **gnl, int fd)
{
	t_gnl		*tmp;
	t_gnl		*save;
	t_gnl		*new;

	tmp = *gnl;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		save = tmp;
		tmp = tmp->next;
	}
	new = (t_gnl *)malloc(sizeof(t_gnl));
	new->fd = fd;
	new->index = 0;
	new->offset = 0;
	new->ret = 0;
	new->end = 0;
	new->next = NULL;
	if (!(*gnl))
		*gnl = new;
	else
		save->next = new;
	return (new);
}

static char	*read_line(t_gnl *gnl)
{
	char	*save;

	save = NULL;
	gnl->offset = gnl->index;
	while (gnl->buf[gnl->offset] != '\n' && gnl->buf[gnl->offset])
		gnl->offset++;
	if (gnl->buf[gnl->offset] == '\n')
	{
		gnl->end = 1;
		gnl->offset++;
	}
	if (gnl->index != gnl->offset)
		save = ft_substr(gnl->buf, gnl->index, gnl->offset - gnl->index);
	gnl->index = gnl->offset;
	return (save);
}

static int	read_fd(t_gnl *current, t_gnl **gnl, char *line)
{
	current->index = 0;
	current->ret = read(current->fd, current->buf, BUFFER_SIZE);
	if (current->ret <= 0 && *line == '\0')
	{
		delete_gnl(gnl, current->fd);
		free(line);
		return (0);
	}
	current->buf[current->ret] = '\0';
	if (!current->ret)
		current->end = 1;
	return (1);
}

char	*get_next_line(int fd)
{
	static t_gnl	*gnl = NULL;
	t_gnl			*current;
	char			*line;

	line = ft_newline(1);
	current = ret_gnl(&gnl, fd);
	while (1)
	{
		current->end = 0;
		if (current->index == current->ret)
			if (!read_fd(current, &gnl, line))
				return (NULL);
		if (current->end)
		{
			delete_gnl(&gnl, current->fd);
			return (line);
		}
		line = ft_strjoin(line, read_line(current));
		if (!line)
			return (NULL);
		if (current->end)
			return (line);
	}
	return (NULL);
}
