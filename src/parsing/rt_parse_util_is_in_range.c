/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_util_is_in_range.c                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: simon2314 <simon2314@42lausanne.ch>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:13:09 by simon2314         #+#    #+#             */
/*   Updated: 2026/01/16 19:24:23 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_higher(char *value, char *limit);
int	dot_handle(char *a, char *b);
int	nega_handle(char *a, char *b);
int	is_only_zero(char *str);

/**
 * @brief	check if the assci argument is in the range comparing caracteres
 *			the value can be negative, enter and rationnal
 * @param	value
 * @param	min
 * @param	max
 * @fonctionnnement the value 
 * @return	1 if it's in range, 0 ifn't
 *
*/

int	rt_parse_util_is_in_range(char *value, char *min, char *max)
{
	if (is_higher(value, min) && is_higher(max, value))
		return (1);
	return (0);
}

/**
 * @brief	check if the ascii value of the first parameter is stricly bigger
 *			than the second
*/

int	is_higher(char *a, char *b)
{
	if (*a == '-' || *b == '-')
		return (nega_handle(a,b));
	while (ft_isdigit(*a) && ft_isdigit(*b))
	{
		if (*a < *b)
			return (0);
		if (*a > *b)
			return (1);
		a++;
		b++;
	}
	if (*a == '.' || *b == '.')
		return (dot_handle(++a, ++b));
	if (ft_isdigit(*b)) // for a case like a = 123, b = 12  
		return (0);
	return (1);
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
	int	a_is_zero;
	int b_is_zero;


	if (ft_isdigit(*a) && *b == '.')
		return (1);
	if (*a == '.' && *b == '.')
		return (is_higher(a, b));
	return (0);
}

int	is_only_zero(char *str)
{
	while (*str)
	{
		if (*str != '0')
			return(0);
	}
	return (1);
}
