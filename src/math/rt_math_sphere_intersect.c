/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_sphere_intersect.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:36:24 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/05 16:39:04 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int rt_math_sphere_intersect(t_ray r, t_shape *sphere, double *t)
{
	t_vec3	oc = rt_math_utils_vec_sub(r.origin, sphere->origin);
    double a = rt_math_utils_vec_dot(r.dir, r.dir);
    double b = 2.0 * rt_math_utils_vec_dot(oc, r.dir);
    double c = rt_math_utils_vec_dot(oc, oc) - sphere->radius * sphere->radius;

	double	delta;

	delta = rt_math_sphere_get_delta(sphere->radius, r.dir, oc);


    if (delta < 0)
        return 0;

    double sqrt_delta = sqrt(delta);
    double t0 = (-b - sqrt_delta) / (2*a);
    double t1 = (-b + sqrt_delta) / (2*a);

    // on prend le plus petit t positif
    if (t0 > 0) *t = t0;
    else if (t1 > 0) *t = t1;
    else return 0;

    return 1;
}

