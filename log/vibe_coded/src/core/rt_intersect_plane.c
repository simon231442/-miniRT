/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersect_plane.c                               :+:      :+:    :+:   */
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

int	rt_intersect_plane(const t_plane *plane, t_ray ray, t_hit *hit)
{
	double	denom;
	double	t;
	t_vec3	diff;
	t_vec3	normal;

	if (plane == NULL || hit == NULL)
		return (0);
	denom = rt_math_vec3_dot(plane->normal, ray.direction);
	if (fabs(denom) < RT_EPSILON)
		return (0);
	diff = rt_math_vec3_sub(plane->point, ray.origin);
	t = rt_math_vec3_dot(diff, plane->normal) / denom;
	if (t < RT_EPSILON)
		return (0);
	normal = plane->normal;
	if (denom > 0.0)
		normal = rt_math_vec3_scale(normal, -1.0);
	hit->hit = 1;
	hit->distance = t;
	hit->point = rt_math_vec3_add(ray.origin,
		rt_math_vec3_scale(ray.direction, t));
	hit->normal = normal;
	hit->color = plane->color;
	return (1);
}
