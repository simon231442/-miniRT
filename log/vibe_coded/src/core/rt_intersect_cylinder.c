/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersect_cylinder.c                            :+:      :+:    :+:   */
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

typedef struct s_cylinder_body
{
	t_vec3	oc;
	t_vec3	d_perp;
	t_vec3	oc_perp;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrt_disc;
	double	half_height;
	double	roots[2];
	double	d_proj;
	double	oc_proj;
}	t_cylinder_body;

typedef struct s_cylinder_cap
{
	t_vec3	center;
	t_vec3	normal;
	double	denom;
	double	t;
	t_vec3	diff;
	t_vec3	point;
	double	radius_sq;
}	t_cylinder_cap;

static int	rt_cylinder_body_candidate(const t_cylinder *cylinder, t_ray ray,
			double root, double half_height, t_hit *hit)
{
	t_vec3	point;
	double	projection;
	t_vec3	axis_point;
	t_vec3	normal;

	if (root <= RT_EPSILON)
		return (0);
	point = rt_math_vec3_add(ray.origin,
		rt_math_vec3_scale(ray.direction, root));
	projection = rt_math_vec3_dot(rt_math_vec3_sub(point, cylinder->center),
						 cylinder->axis);
	if (projection < -half_height || projection > half_height)
		return (0);
	axis_point = rt_math_vec3_add(cylinder->center,
		rt_math_vec3_scale(cylinder->axis, projection));
	normal = rt_math_vec3_sub(point, axis_point);
	hit->hit = 1;
	hit->distance = root;
	hit->point = point;
	hit->normal = rt_math_vec3_normalize(normal);
	hit->color = cylinder->color;
	return (1);
}

static int	rt_cylinder_body(const t_cylinder *cylinder, t_ray ray, t_hit *hit)
{
	t_cylinder_body	state;
	int			index;

	state.half_height = cylinder->height * 0.5;
	state.oc = rt_math_vec3_sub(ray.origin, cylinder->center);
	state.d_proj = rt_math_vec3_dot(ray.direction, cylinder->axis);
	state.oc_proj = rt_math_vec3_dot(state.oc, cylinder->axis);
	state.d_perp = rt_math_vec3_sub(ray.direction,
		rt_math_vec3_scale(cylinder->axis, state.d_proj));
	state.a = rt_math_vec3_dot(state.d_perp, state.d_perp);
	if (fabs(state.a) < RT_EPSILON)
		return (0);
	state.oc_perp = rt_math_vec3_sub(state.oc,
		rt_math_vec3_scale(cylinder->axis, state.oc_proj));
	state.b = 2.0 * rt_math_vec3_dot(state.d_perp, state.oc_perp);
	state.c = rt_math_vec3_dot(state.oc_perp, state.oc_perp)
		- (cylinder->radius * cylinder->radius);
	state.discriminant = (state.b * state.b) - (4.0 * state.a * state.c);
	if (state.discriminant < 0.0)
		return (0);
	state.sqrt_disc = sqrt(state.discriminant);
	state.roots[0] = (-state.b - state.sqrt_disc) / (2.0 * state.a);
	state.roots[1] = (-state.b + state.sqrt_disc) / (2.0 * state.a);
	index = 0;
	while (index < 2)
	{
		if (rt_cylinder_body_candidate(cylinder, ray,
				state.roots[index], state.half_height, hit) != 0)
			return (1);
		index++;
	}
	return (0);
}

static int	rt_cylinder_cap(const t_cylinder *cylinder, t_ray ray,
			 double sign, t_hit *hit)
{
	t_cylinder_cap	state;

	state.normal = rt_math_vec3_scale(cylinder->axis, sign);
	state.center = rt_math_vec3_add(cylinder->center,
		rt_math_vec3_scale(cylinder->axis, (cylinder->height * 0.5) * sign));
	state.radius_sq = cylinder->radius * cylinder->radius;
	state.denom = rt_math_vec3_dot(state.normal, ray.direction);
	if (fabs(state.denom) < RT_EPSILON)
		return (0);
	state.diff = rt_math_vec3_sub(state.center, ray.origin);
	state.t = rt_math_vec3_dot(state.diff, state.normal) / state.denom;
	if (state.t < RT_EPSILON)
		return (0);
	state.point = rt_math_vec3_add(ray.origin,
		rt_math_vec3_scale(ray.direction, state.t));
	state.diff = rt_math_vec3_sub(state.point, state.center);
	if (rt_math_vec3_dot(state.diff, state.diff)
		> state.radius_sq + RT_EPSILON)
		return (0);
	hit->hit = 1;
	hit->distance = state.t;
	hit->point = state.point;
	hit->normal = state.normal;
	hit->color = cylinder->color;
	return (1);
}

static void	rt_cylinder_commit(t_hit *best, t_hit candidate, int *found)
{
	if (*found == 0 || candidate.distance < best->distance)
	{
		*best = candidate;
		*found = 1;
	}
}

int	rt_intersect_cylinder(const t_cylinder *cylinder, t_ray ray, t_hit *hit)
{
	t_hit	candidate;
	int		found;

	if (cylinder == NULL || hit == NULL)
		return (0);
	found = 0;
	if (rt_cylinder_body(cylinder, ray, &candidate) != 0)
		rt_cylinder_commit(hit, candidate, &found);
	if (rt_cylinder_cap(cylinder, ray, 1.0, &candidate) != 0)
		rt_cylinder_commit(hit, candidate, &found);
	if (rt_cylinder_cap(cylinder, ray, -1.0, &candidate) != 0)
		rt_cylinder_commit(hit, candidate, &found);
	hit->hit = found;
	return (found);
}
