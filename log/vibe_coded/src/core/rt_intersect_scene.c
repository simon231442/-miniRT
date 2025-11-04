/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersect_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_intersect.h"

static void	rt_intersect_scene_commit(t_hit *best, t_hit candidate, int *found)
{
	if (*found == 0 || candidate.distance < best->distance)
	{
		*best = candidate;
		*found = 1;
	}
}

static void	rt_intersect_scene_shape(t_shape shape, t_ray ray, t_hit *best, int *found)
{
	t_hit	candidate;

	if (shape.type == RT_SHAPE_SPHERE)
	{
		if (rt_intersect_sphere(&shape.data.sphere, ray, &candidate) != 0)
			rt_intersect_scene_commit(best, candidate, found);
	}
	else if (shape.type == RT_SHAPE_PLANE)
	{
		if (rt_intersect_plane(&shape.data.plane, ray, &candidate) != 0)
			rt_intersect_scene_commit(best, candidate, found);
	}
	else if (shape.type == RT_SHAPE_CYLINDER)
	{
		if (rt_intersect_cylinder(&shape.data.cylinder, ray, &candidate) != 0)
			rt_intersect_scene_commit(best, candidate, found);
	}
}

int	rt_intersect_scene(const t_scene *scene, t_ray ray, t_hit *hit)
{
	size_t	index;
	int		found;

	if (scene == NULL || hit == NULL)
		return (0);
	hit->hit = 0;
	hit->distance = 0.0;
	found = 0;
	index = 0;
	while (index < scene->shape_count)
	{
		rt_intersect_scene_shape(scene->shapes[index], ray, hit, &found);
		index++;
	}
	hit->hit = found;
	return (found);
}
