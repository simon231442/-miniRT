/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_cylinder_intersect_body.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:23:07 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/03 16:19:58 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_cylinder_out_endcap(t_ray r, double t_min, t_shape cylinder)
{
	t_vec3	intersect_point;
	t_vec3	top_endcap;
	double	out_or_not;

	intersect_point = rt_math_get_intersect_point(r, t_min);
	top_endcap = rt_math_utils_vec_add(
			rt_math_utils_vec_multi_scale(cylinder.direction, cylinder.height),
			cylinder.origin);
	out_or_not = rt_math_utils_vec_dot(
			rt_math_utils_vec_sub(top_endcap, intersect_point), 
			cylinder.direction);
	if (out_or_not < 0)
		return (1);
	else if (out_or_not > rt_math_utils_vec_length(rt_math_utils_vec_sub(top_endcap,
					cylinder.origin))) 
		return (1);
	else
		return (0);
}


static void cylinder_delta_abc(t_intersect_view *v, t_ray r, t_shape cylinder)
{
	v->oc = rt_math_utils_vec_sub(r.origin, cylinder.origin);
	v->a = 1 - pow(rt_math_utils_vec_dot(cylinder.direction, r.dir), 2);
	v->b = 2 * (rt_math_utils_vec_dot(r.dir, v->oc) -
			rt_math_utils_vec_dot(cylinder.direction, r.dir) *
			rt_math_utils_vec_dot(cylinder.direction, v->oc));
	v->c = rt_math_utils_vec_dot(v->oc, v->oc) -
			pow(rt_math_utils_vec_dot(cylinder.direction, v->oc), 2) -
			pow(cylinder.radius, 2);
	v->delta = rt_math_utils_get_delta(v->a, v->b, v->c);
}

int	rt_math_cylinder_intersect_body(t_ray r, t_shape cylinder, double *t)
{
	t_intersect_view	v;

	cylinder_delta_abc(&v, r, cylinder);
	if (v.delta < 0)
		return (0);
	v.sqrt_delta = sqrt(v.delta);
	v.t0 = rt_math_utils_get_equation_solutions(v.a, v.b, v.c, v.sqrt_delta, 0);
	//v.t1 = rt_math_utils_get_equation_solutions(v.a, v.b, v.c, v.sqrt_delta, 1);
	if (!check_cylinder_out_endcap(r, v.t0, cylinder))
	{
		*t = v.t0;
		return (1);
	}
	return (0);
}
