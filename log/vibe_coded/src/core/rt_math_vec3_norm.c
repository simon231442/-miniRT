/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_vec3_norm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "rt_math.h"

double	rt_math_vec3_length(t_vec3 v)
{
	double	value;

	value = (v.x * v.x) + (v.y * v.y) + (v.z * v.z);
	return (sqrt(value));
}

t_vec3	rt_math_vec3_normalize(t_vec3 v)
{
	double	length;

	length = rt_math_vec3_length(v);
	if (length < RT_EPSILON)
		return (rt_math_vec3(0.0, 0.0, 0.0));
	return (rt_math_vec3_scale(v, 1.0 / length));
}

double	rt_math_clamp(double value, double min, double max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}
