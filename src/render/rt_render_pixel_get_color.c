/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_pixel_get_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:24:26 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/15 16:04:25 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_render_pixel_get_color(t_la_complete *la_complete, t_render_view v)
{
	t_ray	r;
	t_list	*shape_lst;
	t_list	*last_shape;
	double	t;
	double	t_min;
	t_vec3	intersect_point;
	t_vec3	light_vec;
	t_vec3	normal_vec;
	double	cosinus_angle;
	int		color;

	r.dir = v.pixel_vec;
	r.origin = la_complete->obj.cam.origin;
	shape_lst = la_complete->shape;
	t_min = T_MAX;
	while (shape_lst != NULL)
	{
		if (rt_math_sphere_intersect(r, shape_lst->shape, &t))
		{
			if (t < t_min)
			{
				t_min = t;
			}
		}
		last_shape = shape_lst;
		shape_lst = shape_lst->next;
	}
	if (t_min < T_MAX)
	{
		intersect_point = rt_math_get_intersect_point(v.pixel_vec, t_min);
		light_vec = rt_math_light_get_vec(intersect_point,
				la_complete->obj.light.origin);
		normal_vec = rt_math_sphere_get_normal(intersect_point,
				last_shape->shape->origin);
		cosinus_angle = rt_math_utils_get_cosinus(normal_vec, light_vec);
		color = cosinus_angle * la_complete->obj.light.ratio
			+ rt_parse_utils_get_int_color(la_complete->obj.ambient.color)
			* la_complete->obj.ambient.ratio; //+ obj_color
		color = cosinus_angle * la_complete->obj.light.ratio
			* 0xFFFF00;
		return (color);
	}
	return (0x000000);
}
