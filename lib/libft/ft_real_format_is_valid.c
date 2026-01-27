/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_real_format_is_valid.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon2314 <simon2314@42lausanne.ch>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:11:16 by simon2314         #+#    #+#             */
/*   Updated: 2026/01/19 11:11:16 by simon2314        ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*digit_skip(char *str);

int	ft_real_format_is_valid(char *nb)
{
	if (*nb == '-')
		nb++;
	if (*nb && !ft_isdigit(*nb))
		return (0);
	nb = digit_skip(nb);
	if (!*nb)
		return(1);
	if (*nb == '.')
		nb++;
	nb = digit_skip(nb);
	if (!*nb)
		return(1);
	return (0);
}

static char	*digit_skip(char *str)
{
	while (*str && ft_isdigit(*str))
		str++;
	return (str);
}

