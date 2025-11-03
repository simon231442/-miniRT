/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 08:44:16 by srenaud           #+#    #+#             */
/*   Updated: 2024/10/14 15:34:09 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;

	if (!dest && !src)
		return (NULL);
	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	if (p_dest < p_src)
		return (ft_memcpy(dest, src, n));
	else
	{
		p_dest += n;
		p_src += n;
		while (n > 0)
		{
			p_dest--;
			p_src--;
			*p_dest = *p_src;
			n--;
		}
		return (dest);
	}
}
