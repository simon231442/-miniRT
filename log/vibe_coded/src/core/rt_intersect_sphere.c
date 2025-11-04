/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersect_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "rt_intersect.h"
#include "rt_math.h"

int	rt_intersect_sphere(const t_sphere *sphere, t_ray ray, t_hit *hit)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrt_disc;
	double	root;

	if (sphere == NULL || hit == NULL)
		return (0);
	oc = rt_math_vec3_sub(ray.origin, sphere->center);
	a = rt_math_vec3_dot(ray.direction, ray.direction);
	b = 2.0 * rt_math_vec3_dot(oc, ray.direction);
	c = rt_math_vec3_dot(oc, oc) - (sphere->radius * sphere->radius);
	discriminant = (b * b) - (4.0 * a * c);
	if (discriminant < 0.0)
		return (0);
	sqrt_disc = sqrt(discriminant);
	root = (-b - sqrt_disc) / (2.0 * a);
	if (root < RT_EPSILON)
	{
		root = (-b + sqrt_disc) / (2.0 * a);
		if (root < RT_EPSILON)
			return (0);
	}
	hit->hit = 1;
	hit->distance = root;
	hit->point = rt_math_vec3_add(ray.origin,
		rt_math_vec3_scale(ray.direction, root));
	hit->normal = rt_math_vec3_normalize(rt_math_vec3_sub(hit->point,
			sphere->center));
	hit->color = sphere->color;
	return (1);
}
