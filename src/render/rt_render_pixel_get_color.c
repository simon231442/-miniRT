/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_pixel_get_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:24:26 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/24 16:18:15 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_render_pixel_get_color(t_list *shape, t_obj obj, t_render_view v)
{
	t_ray	r;
	double	t_min;
	t_shape	last_shape;
	double	intensity;
	t_color	color;
	t_list	*shape_list = shape;

	r.dir = v.pixel_vec;
	r.origin = obj.cam.origin;
	if (rt_render_shape_intersect(shape_list, &last_shape, r, &t_min))
	{
		intensity = rt_render_light_get_intensity(shape_list, obj, &last_shape,
				r, t_min);
		color = rt_render_pixel_get_ret_color(last_shape.color,
				obj.ambient, intensity);
		return (rt_parse_utils_get_int_color(color));
	}
	return (0);
}
