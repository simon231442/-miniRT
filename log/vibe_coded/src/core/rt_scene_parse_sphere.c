/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_parse_sphere.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_scene_parser.h"
#include "rt_scene_parser_utils.h"
#include "rt_error.h"

int	rt_scene_parse_sphere(t_scene *scene, char **tokens)
{
	size_t	count;
	t_shape	*shape;
	double	diameter;

	if (scene == NULL)
		return (rt_error("Scene unavailable"));
	if (scene->shape_count >= RT_MAX_SHAPES)
		return (rt_error("Too many objects"));
	count = rt_scene_token_count(tokens);
	if (count != 4)
		return (rt_error("Sphere requires 3 parameters"));
	shape = &scene->shapes[scene->shape_count];
	if (rt_scene_parse_vec3(tokens[1], &shape->data.sphere.center) != 0)
		return (rt_error("Sphere center invalid"));
	if (rt_scene_parse_double(tokens[2], 0.0, 10000.0, &diameter) != 0)
		return (rt_error("Sphere diameter invalid"));
	if (diameter <= 0.0)
		return (rt_error("Sphere diameter invalid"));
	if (rt_scene_parse_color(tokens[3], &shape->data.sphere.color) != 0)
		return (rt_error("Sphere color invalid"));
	shape->type = RT_SHAPE_SPHERE;
	shape->data.sphere.radius = diameter * 0.5;
	scene->shape_count += 1;
	return (0);
}
