/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_real_is_in_range.c                               :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: simon2314 <simon2314@42lausanne.ch>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:13:09 by simon2314         #+#    #+#             */
/*   Updated: 2026/01/29 10:14:54 by srenaud        ########   odam.nl        */
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
	if (is_higher_or_equal(real_value, real_min)
		&& is_higher_or_equal(real_max, real_value))
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
	if (real->int_len == 1 && *real->int_start == '0')
		real->int_len = 0;
}

int	is_higher_or_equal(t_real a, t_real b)
{
	int		i;
	t_real	tmp;

	if (a.nega == 1 && b.nega == 0)
		return (0);
	if (a.nega == 0 && b.nega == 1)
		return (1);
	if (a.nega == 1 && b.nega == 1)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
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
		return (0);
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
