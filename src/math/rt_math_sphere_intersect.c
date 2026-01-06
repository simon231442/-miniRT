/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_sphere_intersect.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:36:24 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/06 17:04:10 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int rt_math_sphere_intersect(t_ray r, t_shape *sphere, double *t)
{
	double	a;
	double	b;
	double	c;
	t_vec3	oc;
	double	delta;
	double	sqrt_delta;
	double	t0;
	double	t1;

	oc = rt_math_utils_vec_sub(r.origin, sphere->origin);
    a = rt_math_utils_vec_dot(r.dir, r.dir);
    b = 2.0 * rt_math_utils_vec_dot(oc, r.dir);
    c = rt_math_utils_vec_dot(oc, oc) - sphere->radius * sphere->radius;
	delta = rt_math_sphere_get_delta(sphere->radius, r.dir, oc);
    if (delta < 0)
        return 0;
    sqrt_delta = sqrt(delta);
    t0 = (-b - sqrt_delta) / (2*a);
    t1 = (-b + sqrt_delta) / (2*a);
    if (t0 > 0)
		*t = t0;
    else if (t1 > 0 && t1 < t0)
		*t = t1;
    else
		return 0;
    return 1;
}
    // on prend le plus petit t positif
