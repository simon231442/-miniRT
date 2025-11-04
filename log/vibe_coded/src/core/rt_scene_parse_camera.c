/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_parse_camera.c                            :+:      :+:    :+:   */
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

int	rt_scene_parse_camera(t_scene *scene, char **tokens)
{
	size_t	count;
	t_vec3	position;
	t_vec3	orientation;
	double	fov;

	if (scene == NULL)
		return (rt_error("Scene unavailable"));
	count = rt_scene_token_count(tokens);
	if (count != 4)
		return (rt_error("Camera requires 3 parameters"));
	if (rt_scene_parse_vec3(tokens[1], &position) != 0)
		return (rt_error("Camera position invalid"));
	if (rt_scene_parse_vec3_normalized(tokens[2], &orientation) != 0)
		return (rt_error("Camera orientation invalid"));
	if (rt_scene_parse_double(tokens[3], 0.0, 180.0, &fov) != 0)
		return (rt_error("Camera FOV invalid"));
	scene->camera.position = position;
	scene->camera.orientation = orientation;
	scene->camera.fov = fov;
	return (0);
}
