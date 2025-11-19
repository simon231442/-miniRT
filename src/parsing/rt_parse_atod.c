/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_atod.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon2314 <simon2314@42lausanne.ch>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:56:48 by simon2314         #+#    #+#             */
/*   Updated: 2025/11/15 16:56:48 by simon2314        ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	after_dot_get(char *value);

double	rt_parse_atod(char *value)
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
		result = result + after_dot_get(&value[++i]);
	return (result * sign);
}

static double	after_dot_get(char *value)
{
	double	result; 
	int	i;

	i = 0;
	result = 0;
	while (value[i])
		i++;
	i--;
	while (i >= 0)
	{
		result = result / 10;
		result = result + value[i] - '0';
		i--;
	}
	result /= 10;
	return (result);
}
