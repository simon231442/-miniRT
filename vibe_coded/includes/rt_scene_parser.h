/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_parser.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_SCENE_PARSER_H
# define RT_SCENE_PARSER_H

# include "rt_structs.h"

int	rt_scene_parse_ambient(t_scene *scene, char **tokens);
int	rt_scene_parse_camera(t_scene *scene, char **tokens);
int	rt_scene_parse_light(t_scene *scene, char **tokens);
int	rt_scene_parse_sphere(t_scene *scene, char **tokens);
int	rt_scene_parse_plane(t_scene *scene, char **tokens);
int	rt_scene_parse_cylinder(t_scene *scene, char **tokens);

#endif
