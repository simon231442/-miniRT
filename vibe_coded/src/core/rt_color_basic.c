/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_basic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_color.h"

#include "rt_math.h"

t_color	rt_color(double r, double g, double b)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_color	rt_color_from_rgb(int r, int g, int b)
{
	t_color	color;

	color.r = rt_math_clamp((double)r / 255.0, 0.0, 1.0);
	color.g = rt_math_clamp((double)g / 255.0, 0.0, 1.0);
	color.b = rt_math_clamp((double)b / 255.0, 0.0, 1.0);
	return (color);
}
