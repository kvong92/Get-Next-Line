/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvong <kvong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:15:36 by kvong             #+#    #+#             */
/*   Updated: 2021/08/10 16:55:45 by kvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_newline(int n)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * n);
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
		str[i++] = '\0';
	return (str);
}

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	int		j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	str = ft_newline(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	ft_strcat(str, s2);
	free(s1);
	free(s2);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
