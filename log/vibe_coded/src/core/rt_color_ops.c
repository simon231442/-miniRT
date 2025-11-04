/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_color.h"

#include "rt_math.h"

t_color	rt_color_add(t_color a, t_color b)
{
	t_color	color;

	color.r = a.r + b.r;
	color.g = a.g + b.g;
	color.b = a.b + b.b;
	return (color);
}

t_color	rt_color_scale(t_color color, double factor)
{
	t_color	result;

	result.r = color.r * factor;
	result.g = color.g * factor;
	result.b = color.b * factor;
	return (result);
}

t_color	rt_color_mul(t_color a, t_color b)
{
	t_color	color;

	color.r = a.r * b.r;
	color.g = a.g * b.g;
	color.b = a.b * b.b;
	return (color);
}

t_color	rt_color_clamp(t_color color, double min, double max)
{
	t_color	result;

	result.r = rt_math_clamp(color.r, min, max);
	result.g = rt_math_clamp(color.g, min, max);
	result.b = rt_math_clamp(color.b, min, max);
	return (result);
}
