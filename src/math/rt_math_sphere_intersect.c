/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_sphere_intersect.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:36:24 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/20 15:46:45 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_math_sphere_intersect(t_ray r, t_shape sphere, double *t)
{
	t_intersect_view	v;

	v.oc = rt_math_utils_vec_sub(r.origin, sphere.origin);
	v.a = rt_math_utils_vec_dot(r.dir, r.dir);
	v.b = 2.0 * rt_math_utils_vec_dot(v.oc, r.dir);
	v.c = rt_math_utils_vec_dot(v.oc, v.oc) - sphere.radius * sphere.radius;
	v.delta = v.b * v.b - 4 * v.a * v.c;
	if (v.delta < 0)
		return (0);
	v.sqrt_delta = sqrt(v.delta);
	v.t0 = (-v.b - v.sqrt_delta) / (2 * v.a);
	v.t1 = (-v.b + v.sqrt_delta) / (2 * v.a);
	if (v.t0 > 0)
		*t = v.t0;
	else if (v.t1 > 0)
		*t = v.t1;
	else
		return (0);
	return (1);
}
