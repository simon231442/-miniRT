/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_cam.c                                      :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:28:02 by srenaud           #+#    #+#             */
/*   Updated: 2025/11/21 15:05:58 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/** 
 * @brief	parse a camera line and fill la_complete->obj.cam
 			camera's parametres : origin, direction, fov 
 * @return	0 on success, ERROR_SYSTEM or ... 
*/
int rt_parse_cam(char *line, t_la_complete *la_complete)
{
	char	**arg;

	arg = ft_split(line, ' ');
	if (!arg)
		return (ERROR_SYSTEM);
	if (rt_parse_vector(arg[1], &la_complete->obj.cam.origin) ||
		rt_parse_vector(arg[2], &la_complete->obj.cam.direction))
		return (free(arg), 1);
	la_complete->obj.cam.fov = rt_parse_atod(arg[3]);
	return (free(arg), 0);
}

