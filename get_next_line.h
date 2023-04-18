/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvong <kvong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:15:12 by kvong             #+#    #+#             */
/*   Updated: 2021/08/09 18:15:13 by kvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl
{
	int				fd;
	int				index;
	int				offset;
	int				end;
	int				ret;
	char			buf[BUFFER_SIZE + 1];
	struct s_gnl	*next;
}					t_gnl;

char				*get_next_line(int line);
size_t				ft_strlen(const char *s);
char				*ft_newline(int n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);

#endif
