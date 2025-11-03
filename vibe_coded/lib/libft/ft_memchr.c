/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:34:33 by srenaud           #+#    #+#             */
/*   Updated: 2024/10/11 14:02:20 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*c_s;
	size_t			i;

	c_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (c_s[i] == (unsigned char)c)
			return ((void *)&c_s[i]);
		i++;
	}
	return (NULL);
}
