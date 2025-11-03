/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:10:16 by srenaud           #+#    #+#             */
/*   Updated: 2024/10/14 16:15:29 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	l_dest;
	size_t	i;

	l_dest = ft_strlen(dest);
	i = 0;
	if (size <= l_dest)
		return (size + ft_strlen(src));
	while (l_dest + i < size - 1 && src[i])
	{
		dest[l_dest + i] = src[i];
		i++;
	}
	dest[l_dest + i] = '\0';
	return (l_dest + ft_strlen(src));
}
