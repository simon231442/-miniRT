/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_utils_is_higher_or_equal.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon2314 <simon2314@42lausanne.ch>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:05:06 by simon2314         #+#    #+#             */
/*   Updated: 2026/01/18 14:05:06 by simon2314        ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	dot_handle(char *a, char *b);
int	nega_handle(char *a, char *b);
int	is_only_zero(char *str);
/**
 * @brief	check if the ascii value of the first parameter is stricly bigger
 *			than the second
*/

int	rt_parse_utils_is_higher_or_equal(char *a, char *b)
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
			return (rt_parse_utils_is_higher_or_equal(b, a));
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
//	int	a_is_zero;
//	int b_is_zero;


	if (ft_isdigit(*a) && *b == '.')
		return (1);
	if (*a == '.' && *b == '.')
		return (rt_parse_utils_is_higher_or_equal(a, b));
	return (0);
}
/*
int	is_only_zero(char *str)
{
	while (*str)
	{
		if (*str != '0')
			return(0);
	}
	return (1);
}
*/
