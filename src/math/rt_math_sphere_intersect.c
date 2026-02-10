/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_sphere_intersect.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:36:24 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/10 15:40:30 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_math.h"

int	rt_math_sphere_intersect(t_ray r, t_shape sphere, double *t)
{
	t_intersect_view	v;

	v.oc = rt_math_utils_vec_sub(r.origin, sphere.origin);
	v.a = rt_math_utils_vec_dot(r.dir, r.dir);
	v.b = 2.0 * rt_math_utils_vec_dot(v.oc, r.dir);
	v.c = rt_math_utils_vec_dot(v.oc, v.oc) - sphere.radius * sphere.radius;
	v.delta = rt_math_utils_get_delta(v.a, v.b, v.c);
	if (v.delta < 0)
		return (0);
	v.sqrt_delta = sqrt(v.delta);
	v.t0 = rt_math_utils_get_equation_solutions(v, 0);
	v.t1 = rt_math_utils_get_equation_solutions(v, 1);
	if (v.t0 > EPSILON)
		*t = v.t0;
	else if (v.t1 > EPSILON)
		*t = v.t1;
	else
		return (0);
	return (1);
}
