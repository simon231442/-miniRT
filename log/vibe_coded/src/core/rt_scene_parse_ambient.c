/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_parse_ambient.c                           :+:      :+:    :+:   */
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

int	rt_scene_parse_ambient(t_scene *scene, char **tokens)
{
	size_t	count;
	double	ratio;
	t_color	color;

	if (scene == NULL)
		return (rt_error("Scene unavailable"));
	count = rt_scene_token_count(tokens);
	if (count != 3)
		return (rt_error("Ambient requires 2 parameters"));
	if (rt_scene_parse_double(tokens[1], 0.0, 1.0, &ratio) != 0)
		return (rt_error("Ambient ratio invalid"));
	if (rt_scene_parse_color(tokens[2], &color) != 0)
		return (rt_error("Ambient color invalid"));
	scene->ambient.ratio = ratio;
	scene->ambient.color = color;
	return (0);
}
