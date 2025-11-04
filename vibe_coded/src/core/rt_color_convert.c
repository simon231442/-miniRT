/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_color.h"

int	rt_color_to_int(t_color color)
{
	int	r;
	int	g;
	int	b;
	t_color	clamped;

	clamped = rt_color_clamp(color, 0.0, 1.0);
	r = (int)((clamped.r * 255.0) + 0.5);
	g = (int)((clamped.g * 255.0) + 0.5);
	b = (int)((clamped.b * 255.0) + 0.5);
	return ((r << 16) | (g << 8) | b);
}
