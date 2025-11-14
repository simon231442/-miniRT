/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_value.c                                    :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:17:55 by srenaud           #+#    #+#             */
/*   Updated: 2025/11/13 16:37:41 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	after_dot_get(char *value);

double	rt_parse_value(char *value)
{
	double	result;
	int		i;
	double	sign;

	i = 0;
	sign = 1; 
	result = 0;
	if (value[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (value[i] != '.' && value[i])
	{
		result = result * 10 + value[i] - '0';
		i++;
	}
	if (value[i] == '.')
		result = result after_dot_get(&value[++i]);
	return (result * sign);
}

static double	after_dot_get(char *value)
{
	double	result; 
	int	i;

	i = 0;
	result = 1;
	while (value[i])
		i++;
	result = value[--i] - '0';
	i--;
	while (i >= 0)
	{
		result = result / 10 + value[i] - '0';
		i--;
	}
	return (result);
}
