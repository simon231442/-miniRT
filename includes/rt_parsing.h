/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.h                                        :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: simon2314 <simon2314@42lausanne.ch>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:00:32 by simon2314         #+#    #+#             */
/*   Updated: 2025/12/01 14:11:11 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSING_H
# define RT_PARSING_H

typedef struct s_la_complete t_la_complete;
typedef enum e_error_type t_error_type;
typedef struct s_vec3 t_vec3;
typedef struct s_color t_color;

typedef struct s_parser
{
	char	*identifier;
	int		(*f)(char *line, t_la_complete *la_complete);
}	t_parser;
	
int		rt_parse(char *path, t_la_complete *la_complet);
int		rt_parse_ambient(char *line, t_la_complete *la_complete);
int 	rt_parse_cam(char *line, t_la_complete *la_complete);
int		rt_parse_light(char *line, t_la_complete *la_complete);
int 	rt_parse_shape_sphere(char *line, t_la_complete *la_complete);
int		rt_parse_shape_plane(char *line, t_la_complete *la_complete);
int		rt_parse_shape_cylinder(char *line, t_la_complete *la_complete);
double	rt_parse_util_atod(char *value);
int		rt_parse_util_vector(char *arg, t_vec3 *vector);
int		rt_parse_util_color(char *arg, t_color *color);
int		rt_parse_util_is_in_range(char *value, char *min, char *max);
int		rt_parse_utils_is_higher_or_equal(char *a, char *b);

void	rt_parse_util_line_clean(char *line);
void	rt_parse_util_arg_free(char **arg);
void	rt_parse_util_shape_free(t_la_complete *la_complete);

#endif

