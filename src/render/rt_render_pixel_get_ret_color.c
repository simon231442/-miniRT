/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_pixel_get_ret_color.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:03:35 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/31 16:24:01 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	rt_render_pixel_get_ret_color(t_color shape_color, t_ambient ambient,
			double intensity)
{
	t_color	ret_color;

	ret_color.r = shape_color.r * (ambient.ratio * ambient.color.r / 255
			+ intensity);
	ret_color.g = shape_color.g * (ambient.ratio * ambient.color.g / 255
			+ intensity);
	ret_color.b = shape_color.b * (ambient.ratio * ambient.color.b / 255
			+ intensity);
	if (ret_color.r > 255)
		ret_color.r = 255;
	if (ret_color.g > 255)
		ret_color.g = 255;
	if (ret_color.b > 255)
		ret_color.b = 255;
	return (ret_color);
}
	//ambient.ratio * ambient.color.r / 255.0
