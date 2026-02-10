/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_pixel_get_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:24:26 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/10 15:47:20 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_render.h"
#include "rt_parsing.h"

int	rt_render_pixel_get_color(t_list *shape, t_obj obj, t_render_view v)
{
	t_pixel_view	p;

	p.shape_list = shape;
	p.r.dir = v.pixel_vec;
	p.r.origin = obj.cam.origin;
	if (rt_render_shape_intersect(p.shape_list, &p.last_shape, p.r, &p.t_min))
	{
		p.intensity = rt_render_light_get_intensity(&p, obj);
		p.color = rt_render_pixel_get_ret_color(p.last_shape->color,
				obj.ambient, p.intensity);
		return (rt_parse_utils_get_int_color(p.color));
	}
	return (0);
}
