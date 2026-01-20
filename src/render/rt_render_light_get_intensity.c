/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_light_get_intensity.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 13:52:52 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/20 15:36:33 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	rt_render_light_get_intensity(t_la_complete *c,
		t_list *last_shape, t_ray r, double t_min)
{
	t_vec3	intersect_point;
	t_vec3	light_vec;
	t_vec3	normal_vec;
	double	cosinus_angle;
	double	intensity;

	intersect_point = rt_math_get_intersect_point(r, t_min);
	light_vec = rt_math_light_get_vec(intersect_point,
			c->obj.light.origin);
	///////////////////////////////
	//fonction pour definir quelle normal prendre 
	//possible de lunir avec l'intersect ????????????????????
	if (last_shape->shape->type == SPHERE)
		normal_vec = rt_math_sphere_get_normal(intersect_point,
			last_shape->shape->origin);
	else if (last_shape->shape->type == PLANE)
		normal_vec = last_shape->shape->direction;
	else if (last_shape->shape->type == CYLINDER)
		normal_vec = rt_math_cylinder_get_normal();
	cosinus_angle = rt_math_utils_get_cosinus(normal_vec, light_vec);
//	if (cosinus_angle < 0)
//		return (0);
	intensity = cosinus_angle * c->obj.light.ratio
		+ c->obj.ambient.ratio; //+ obj_color
	if (intensity > 1)
		intensity = 1;
	else if (intensity < 0)
		intensity = 0;
	return (intensity);
}
