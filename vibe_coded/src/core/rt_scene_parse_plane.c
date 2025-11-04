/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_parse_plane.c                             :+:      :+:    :+:   */
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

int	rt_scene_parse_plane(t_scene *scene, char **tokens)
{
	size_t	count;
	t_shape	*shape;

	if (scene == NULL)
		return (rt_error("Scene unavailable"));
	if (scene->shape_count >= RT_MAX_SHAPES)
		return (rt_error("Too many objects"));
	count = rt_scene_token_count(tokens);
	if (count != 4)
		return (rt_error("Plane requires 3 parameters"));
	shape = &scene->shapes[scene->shape_count];
	if (rt_scene_parse_vec3(tokens[1], &shape->data.plane.point) != 0)
		return (rt_error("Plane point invalid"));
	if (rt_scene_parse_vec3_normalized(tokens[2], &shape->data.plane.normal) != 0)
		return (rt_error("Plane normal invalid"));
	if (rt_scene_parse_color(tokens[3], &shape->data.plane.color) != 0)
		return (rt_error("Plane color invalid"));
	shape->type = RT_SHAPE_PLANE;
	scene->shape_count += 1;
	return (0);
}
