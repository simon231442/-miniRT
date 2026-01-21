/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_pixel_get_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:24:26 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/21 12:10:36 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_render_pixel_get_color(t_la_complete *la_complete, t_render_view v)
{
	t_get_color_view	c;

	c.r.dir = v.pixel_vec;
	c.r.origin = la_complete->obj.cam.origin;
	c.shape_lst = la_complete->shape;
	c.t_min = T_MAX;
	while (c.shape_lst != NULL)
	{
		if (rt_math_shape_intersect(c.r, *c.shape_lst->shape, &c.t))
		{
			if (c.t < c.t_min)
			{
				c.t_min = c.t;
				c.last_shape = c.shape_lst;
			}
		}
		c.shape_lst = c.shape_lst->next;
	}
	if (c.t_min < T_MAX)
	{
		c.intensity = rt_render_light_get_intensity(la_complete, c.last_shape,
				c.r, c.t_min);
		c.color = rt_render_pixel_get_ret_color(c.last_shape->shape->color,
				la_complete->obj.ambient, c.intensity);
		return (rt_parse_utils_get_int_color(c.color));
	}
	return (0);
}
