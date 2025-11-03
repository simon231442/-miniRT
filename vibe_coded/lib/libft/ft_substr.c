/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:18:41 by srenaud           #+#    #+#             */
/*   Updated: 2024/10/15 09:44:28 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_start;
	size_t	i;

	s_start = (size_t)start;
	if (s_start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - s_start)
		len = ft_strlen(s) - s_start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[s_start + i])
	{
		sub[i] = s[s_start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
