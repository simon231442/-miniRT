/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.h                                        :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: simon2314 <simon2314@42lausanne.ch>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:00:32 by simon2314         #+#    #+#             */
/*   Updated: 2025/11/20 08:44:56 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PARSING_H
# define RT_PARSING_H

typedef struct s_la_complete t_la_complete;
typedef enum e_error_type t_error_type;
typedef struct s_vec3 t_vec3;

int 	rt_parse_cam(char *line, t_la_complete *la_complete);
double	rt_parse_atod(char *value);
int		rt_parse_vector(char *arg, t_vec3 *vector);

#endif

