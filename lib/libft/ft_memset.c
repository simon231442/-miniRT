/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:39:49 by srenaud           #+#    #+#             */
/*   Updated: 2024/10/02 00:39:49 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p_s;
	unsigned char	c_c;

	p_s = (unsigned char *)s;
	c_c = (unsigned char)c;
	while (n > 0)
	{
		*p_s = c_c;
		p_s++;
		n--;
	}
	return (s);
}
