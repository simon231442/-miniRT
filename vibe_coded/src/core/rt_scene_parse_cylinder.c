/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_parse_cylinder.c                          :+:      :+:    :+:   */
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

int	rt_scene_parse_cylinder(t_scene *scene, char **tokens)
{
	size_t	count;
	t_shape	*shape;
	double	diameter;
	double	height;

	if (scene == NULL)
		return (rt_error("Scene unavailable"));
	if (scene->shape_count >= RT_MAX_SHAPES)
		return (rt_error("Too many objects"));
	count = rt_scene_token_count(tokens);
	if (count != 6)
		return (rt_error("Cylinder requires 5 parameters"));
	shape = &scene->shapes[scene->shape_count];
	if (rt_scene_parse_vec3(tokens[1], &shape->data.cylinder.center) != 0)
		return (rt_error("Cylinder center invalid"));
	if (rt_scene_parse_vec3_normalized(tokens[2], &shape->data.cylinder.axis) != 0)
		return (rt_error("Cylinder axis invalid"));
	if (rt_scene_parse_double(tokens[3], 0.0, 10000.0, &diameter) != 0)
		return (rt_error("Cylinder diameter invalid"));
	if (rt_scene_parse_double(tokens[4], 0.0, 10000.0, &height) != 0)
		return (rt_error("Cylinder height invalid"));
	if (diameter <= 0.0 || height <= 0.0)
		return (rt_error("Cylinder dimensions invalid"));
	if (rt_scene_parse_color(tokens[5], &shape->data.cylinder.color) != 0)
		return (rt_error("Cylinder color invalid"));
	shape->type = RT_SHAPE_CYLINDER;
	shape->data.cylinder.radius = diameter * 0.5;
	shape->data.cylinder.height = height;
	scene->shape_count += 1;
	return (0);
}
