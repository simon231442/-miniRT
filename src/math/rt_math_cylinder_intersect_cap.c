/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_cylinder_intersect_cap.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:23:35 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/01 15:56:05 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	intersect_cap_top(t_ray r, t_shape cylinder, double *t)
{
	t_shape	cap;
	t_vec3	intersect_point;
	double	distance_from_ori;

	cap.origin = rt_math_utils_vec_add(
			rt_math_utils_vec_multi_scale(cylinder.direction, cylinder.height),
			cylinder.origin);
	cap.direction = cylinder.direction; 
	if (!rt_math_plane_intersect(r, cap, t))
		return (0);
	intersect_point = rt_math_get_intersect_point(r, *t);
	distance_from_ori = rt_math_utils_point_distance(intersect_point, cap.origin);
	if (distance_from_ori <= cylinder.radius)
		return (1);
	return (0);
}

static int	intersect_cap_bottom(t_ray r, t_shape cylinder, double *t)
{
	t_shape	cap;
	t_vec3	intersect_point;
	double	distance_from_ori;

	cap.origin = cylinder.origin;
	cap.direction = rt_math_utils_vec_multi_scale(cylinder.direction, -1); 
	if (!rt_math_plane_intersect(r, cap, t))
		return (0);
	intersect_point = rt_math_get_intersect_point(r, *t);
	distance_from_ori = rt_math_utils_point_distance(intersect_point, cap.origin);
	if (distance_from_ori <= cylinder.radius)
		return (1);
	return (0);
}

int	rt_math_cylinder_intersect_cap(t_ray r, t_shape *cylinder, double *t)
{
	double	t_min;

	t_min = T_MAX;
	if (intersect_cap_bottom(r, *cylinder, t))	
		t_min = *t;
	if (intersect_cap_top(r, *cylinder, t))
	{
		if (*t < t_min)
		{
			cylinder->hit_type = TOP;
			return (1);
		}
	}
	if (t_min != T_MAX)
	{
		*t = t_min;
		cylinder->hit_type = BOTTOM;
		return (1);
	}
	return (0);
}
