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

int decimal_counter(char *a);

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
	int decimal_diff_min;

	decimal_diff_max = decimal_counter(max) - decimal_counter(value);
	decimal_diff_min = decimal_counter(min) - decimal_counter(value);

	if (decimal_diff_max < 0 || decimal_diff_min > 0)
		return (0);
	if (decimal_diff_max > 0 && decimal_diff_min < 0)
		return (1);
	if (decimal_diff_max == 0)
	{
		if (decimal_diff_min == 0 && rt_parse_utils_is_higher_or_equal(value, min) && rt_parse_utils_is_higher_or_equal(max, value))// cas ou la value a le meme nb de decimal que min et max)
			return (1);
		if (decimal_diff_min < 0 && rt_parse_utils_is_higher_or_equal(max, value))//dicimal_diff_min < 0 ---> valeur plus grand que min //cas ou la value a le meme nb de decimal que max et min deja ok) 
			return (0);
		else
			return (1);
	}
	if (decimal_diff_min == 0 && decimal_diff_max > 0 && rt_parse_utils_is_higher_or_equal(value, min))// decimal_diff_mah
		return (1);
	/*	
	if (rt_parse_utils_is_higher_or_equal(value, min) && rt_parse_utils_is_higher_or_equal(max, value))
		return (1); */
	return (0);
}

int decimal_counter(char *a)
{
	int	count;

	count = 0;
	if (*a == '-')
		a++;
	while (*a && ft_isdigit(*a))
	{
		count++;
		a++;
	}
	return (count);
}

int	is_smaller_or_equal_to_max(char *value, char *max)
{
	int	decimal_diff;
	
	decimal_diff = decimal_counter(max) - decimal_counter(value);
	if (*value == '-')
	{
		if (*max != '-')
			retrurn (1);
		if (*max == '-')
		{
			if (decimal_diff > 0)
				return (1);
			if (decimal_diff == 0)
			{
				if (rt_parse_utils_is_higher_or_equal(max, value))
					return (1);
				else
					return (0);
			}
			return (0);
		}
	}
	if (*max == '-')
		return (0);
	if (*max != '-')
	{
		if (decimal_diff > 0)
			return (1);
		if (decimal_diff == 0)
		{
			if (rt_parse_utils_is_higher_or_equal(max, value))
				return (1);
			else
				return (0);
		}
		return (0);
	}
}

int	is_higher_or_equal_to_min(char *value, char *min)
{
	int	decimal_diff;

	deccimal_diff = decimalcounter(min) - decimal_counter(value);
	if (decimal_diff == 0)
		return (rt_parse_utils_is_higher_or_equal(value, max);
	if (*value == '-')
	{
		if (*min != '-')
			return (0);
		if (*min == '-')
		{
			if (decimal_diff > 0)
				return (1);
			if (decimal_diff < 0)
				return (0);
		}
	}
	if (*min == '-')
		return (1);
	if (*
	

	

