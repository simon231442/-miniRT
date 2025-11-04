/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_parser_utils.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_SCENE_PARSER_UTILS_H
# define RT_SCENE_PARSER_UTILS_H

# include "rt_structs.h"

int	rt_scene_parse_double(const char *str, double min, double max, double *out);
int	rt_scene_parse_vec3(const char *str, t_vec3 *out);
int	rt_scene_parse_vec3_normalized(const char *str, t_vec3 *out);
int	rt_scene_parse_color(const char *str, t_color *out);
int	rt_scene_is_empty_line(const char *line);
size_t	rt_scene_token_count(char **tokens);

#endif
