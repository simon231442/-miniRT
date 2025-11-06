/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:01:58 by srenaud           #+#    #+#             */
/*   Updated: 2025/01/10 18:00:51 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*gnl_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*gnl_strjoin(char *stash, char *buff)
{
	char	*str;

	if (!stash || !buff)
		return (NULL);
	str = malloc(sizeof(char) * (gnl_strlen(stash) + gnl_strlen(buff) + 1));
	if (!str)
		return (NULL);
	gnl_strcpy(str, stash);
	gnl_strcat(str, buff);
	return (str);
}

void	gnl_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	gnl_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	 len;

	i = 0;
	len = gnl_strlen(dest);
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
}
