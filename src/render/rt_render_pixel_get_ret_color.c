/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_pixel_get_ret_color.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:03:35 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/20 15:39:07 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	rt_render_pixel_get_ret_color(t_color shape_color, t_ambient ambient,
			double intensity)
{
	t_color	ret_color;
	double	multiply_color;

	multiply_color = intensity * 255;
	ret_color.r = (shape_color.r / 255.0) * multiply_color
		+ ambient.ratio * ambient.color.r;
	ret_color.g = (shape_color.g / 255.0) * multiply_color
		+ ambient.ratio * ambient.color.g;
	ret_color.b = (shape_color.b / 255.0) * multiply_color
		+ ambient.ratio * ambient.color.b;
	return (ret_color);
}
