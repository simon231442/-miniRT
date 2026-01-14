/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_util_is_in_range.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon2314 <simon2314@42lausanne.ch>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:13:09 by simon2314         #+#    #+#             */
/*   Updated: 2025/12/29 15:13:09 by simon2314        ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_higher(char *value, char *limit);
int	dot_handle(char *a, char *b);
int	nega_handle(char *a, char *b);

/**
 * @brief	check if the assci argument is in the range
 * @return	1 if it's in range, 0 ifn't
 *
*/

int	rt_parse_util_is_in_range(char *value, char *min, char *max)
{
	if (!is_higher(min, value) && is_higher(value, max))
		return (1);
	return (0);
}

int	is_higher(char *a, char *b)
{
	if (*a == '-' || *b == '-')
		return (nega_handle(a,b));
	while (ft_isdigit(*a) && ft_isdigit(*b))
	{
		if (*a < *b)
			return (0);
		a++;
		b++;
	}
	if (*a == '.' || *b == '.')
		return (dot_handle(++a, ++b));
	if (ft_isdigit(*a)) 
		return (1);
	return (0);
}

int	nega_handle(char *a, char *b)
{
	if (*a == '-' && *b == '-')
	{
		a++;
		b++;
		if (ft_isdigit(*a) && ft_isdigit(*b))
			return (is_higher(b, a));
		else
			return (1);
	}
	else if (*a != '-' && *b == '-')
		return (1);
	else if (*a == '-' && *b != '-')
		return (0);
	return (0);
}

int	dot_handle(char *a, char *b)
{
	if (ft_isdigit(*a) && *b == '.')
		return (1);
	if (*a == '.' && *b == '.')
		return (is_higher(a, b));
	return (0);
}

