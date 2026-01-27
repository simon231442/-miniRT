/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_real_is_in_range.c                         :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: simon2314 <simon2314@42lausanne.ch>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:13:09 by simon2314         #+#    #+#             */
/*   Updated: 2026/01/16 19:24:23 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	real_set(t_real *real, char *raw);
int		is_higher_or_equal(t_real a, t_real b);
int		fract_is_higher_or_equal(t_real a, t_real b);

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

int	ft_real_is_in_range(char *value, char *min, char *max)
{
	t_real	real_value;
	t_real	real_min;
	t_real	real_max;

	real_set(&real_value, value);
	real_set(&real_min, min);
	real_set(&real_max, max);
	if (is_higher_or_equal(real_value, real_min) && is_higher_or_equal(real_max, real_value))
		return (1);
	return (0);
}

void	real_set(t_real *real, char *raw)
{
	char	*dot;
	real->raw = raw;
	if (raw[0] == '-')
	{
		real->nega = 1;
		raw++;
	}
	else
		real->nega = 0;
	real->int_start = raw;
	dot = ft_strchr(raw, '.');
	if (dot)
	{
		real->int_len = dot - raw;
		real->fract_start = dot + 1;
	}
	else
	{
		real->int_len = ft_strchr(raw, '\0') - raw;
		real->fract_start = NULL;
	}
}

int	is_higher_or_equal(t_real a, t_real b)
{
	int	i;

	if (a.nega == 1 && b.nega == 0)
		return (0);
	if (a.nega == 0 && b.nega == 1)
		return (1);
	if (a.int_len > b.int_len)
		return (1);
	if (a.int_len < b.int_len)
		return (0);
	i = 0;
	while (i < a.int_len)
	{
		if (a.int_start[i] > b.int_start[i])
			return (1);
		if (a.int_start[i] < b.int_start[i])
			return (0);
		i++;
	}
	if (fract_is_higher_or_equal(a, b))
		return (1);
	return (0);
}	

int	fract_is_higher_or_equal(t_real a, t_real b)
{
	int	i;

	if (!b.fract_start)
		return (1);
	if (!a.fract_start)
	{
		if (ft_is_zero_only(b.fract_start))
			return (1);
		return(0);
	}
	i = 0;
	while (a.fract_start[i] && b.fract_start[i])
	{
		if (a.fract_start[i] > b.fract_start[i])
			return (1);
		if (a.fract_start[i] < b.fract_start[i])
			return (0);
		i++;
	}
	if (a.fract_start[i] > b.fract_start[i])
		return (1);
	if (a.fract_start[i] < b.fract_start[i])
		return (0);
	return (1);
}
	
/*
int	ft_real_is_in_range(char *value, char *min, char *max)
{
	if (is_lower_or_equal_to_max(value, max) && is_higher_or_equal_to_min(value, min))
		return (1);
	return (0);
}

int	is_lower_or_equal_to_max(char *value, char *max)
{
	int	decimal_diff;
	
	decimal_diff = decimal_counter(max) - decimal_counter(value);
	if (*value == '-')
	{
		if (*max != '-')
			return (1);
		if (*max == '-')
		{
			if (decimal_diff > 0)
				return (1);
			if (decimal_diff == 0)
			{
				if (ft_real_equal_decimals_is_higher_or_equal(max, value))
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
			if (ft_real_equal_decimals_is_higher_or_equal(max, value))
				return (1);
			else
				return (0);
		}
		return (0);
	}
	return (0);
}

int	is_higher_or_equal_to_min(char *value, char *min)
{
	int	decimal_diff;

	decimal_diff = decimal_counter(min) - decimal_counter(value);
	if (decimal_diff == 0)
		return (ft_real_equal_decimals_is_higher_or_equal(value, min));
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
	if (*min != '-')
	{
		if (decimal_diff > 0)
			return (0);
		if (decimal_diff < 0)
			return (1);
	}
	return (0);
}

int decimal_counter(char *a)
{
	int	count;

	count = 0;
	if (*a == '-')
		a++;
	while (*a == '0')
		a++;
	while (*a && ft_isdigit(*a))
	{
		count++;
		a++;
	}
	return (count);
}
*/
