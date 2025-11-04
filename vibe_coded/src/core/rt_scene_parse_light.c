/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_parse_light.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_scene_parser.h"
#include "rt_scene_parser_utils.h"
#include "rt_color.h"
#include "rt_error.h"

int	rt_scene_parse_light(t_scene *scene, char **tokens)
{
	size_t	count;
	t_vec3	position;
	double	brightness;
	t_color	color;

	if (scene == NULL)
		return (rt_error("Scene unavailable"));
	count = rt_scene_token_count(tokens);
	if (count != 3 && count != 4)
		return (rt_error("Light requires 2 or 3 parameters"));
	if (rt_scene_parse_vec3(tokens[1], &position) != 0)
		return (rt_error("Light position invalid"));
	if (rt_scene_parse_double(tokens[2], 0.0, 1.0, &brightness) != 0)
		return (rt_error("Light brightness invalid"));
	color = rt_color(1.0, 1.0, 1.0);
	if (count == 4)
	{
		if (rt_scene_parse_color(tokens[3], &color) != 0)
			return (rt_error("Light color invalid"));
	}
	scene->light.position = position;
	scene->light.brightness = brightness;
	scene->light.color = color;
	return (0);
}
