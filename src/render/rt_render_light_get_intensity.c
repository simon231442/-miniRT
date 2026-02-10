/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_light_get_intensity.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 13:52:52 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/10 15:48:27 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_render.h"

double	rt_render_light_get_intensity(t_pixel_view *p, t_obj obj)
{
	t_light_view	l;

	l.intersect_point = rt_math_get_intersect_point(p->r, p->t_min);
	l.light_ray.origin = l.intersect_point;
	l.light_ray.dir = rt_math_light_get_vec(l.intersect_point,
			obj.light.origin);
	l.light_distance = rt_math_utils_point_distance(l.intersect_point,
			obj.light.origin);
	if (rt_render_shadow_intersect(p->shape_list, &p->last_shape,
			l.light_ray, l.light_distance))
		return (0);
	l.normal_vec = rt_math_shape_get_normal(l.intersect_point, *p->last_shape);
	l.cosinus_angle = rt_math_utils_get_cosinus(l.normal_vec, l.light_ray.dir);
	l.intensity = l.cosinus_angle * obj.light.ratio;
	if (l.intensity > 1)
		l.intensity = 1;
	else if (l.intensity < 0)
		l.intensity = 0;
	return (l.intensity);
}
