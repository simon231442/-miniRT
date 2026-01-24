/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_light_get_intensity.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 13:52:52 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/24 16:44:45 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	rt_render_light_get_intensity(t_list *shape, t_obj obj,
		t_shape *act_shape, t_ray r, double t_min)
{
	t_vec3	intersect_point;
	t_vec3	light_vec;
	t_vec3	normal_vec;
	double	cosinus_angle;
	double	intensity;

	intersect_point = rt_math_get_intersect_point(r, t_min);
	light_vec = rt_math_light_get_vec(intersect_point,
			obj.light.origin);
	//if intersection avec un objet
	//return (0);
	//parcourir les shape ()
		//sur chaque shape rt_math_shape_intersect
	normal_vec = rt_math_shape_get_normal(intersect_point, act_shape);
	cosinus_angle = rt_math_utils_get_cosinus(normal_vec, light_vec);
	intensity = cosinus_angle * obj.light.ratio
		+ obj.ambient.ratio; //+ obj_color
	if (intensity > 1)
		intensity = 1;
	else if (intensity < 0)
		intensity = 0;
	return (intensity);
}

///double	rt_render_light_get_intensity(t_list *shape, t_obj obj,
///		t_shape *act_shape, t_ray r, double t_min)
///{
///	t_vec3	intersect_point;
///	t_vec3	normal_vec;
///	double	cosinus_angle;
///	double	intensity;
///	t_vec3	light_vec;
///	t_ray	light_ray;
///
///	intersect_point = rt_math_get_intersect_point(r, t_min);
///	light_ray.origin = obj.light.origin;
///	light_vec = rt_math_light_get_vec(intersect_point, obj.light.origin);
///	(void)shape;
//////	if (rt_render_shape_intersect(shape, &act_shape, light_ray, &t_min))
//////		return (0);
///	normal_vec = rt_math_shape_get_normal(intersect_point, act_shape);
///	cosinus_angle = rt_math_utils_get_cosinus(normal_vec, light_vec);
///	intensity = cosinus_angle * obj.light.ratio
///		+ obj.ambient.ratio; //+ obj_color
///	if (intensity > 1)
///		intensity = 1;
///	else if (intensity < 0)
///		intensity = 0;
///	return (intensity);
///}
