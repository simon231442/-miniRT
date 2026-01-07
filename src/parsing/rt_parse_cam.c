/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:28:02 by srenaud           #+#    #+#             */
/*   Updated: 2026/01/07 16:45:56 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/** 
 * @brief	parse a camera line and fill la_complete->obj.cam
 			camera's parametres : origin, direction, fov 
 * @return	0 on success, ERROR_SYSTEM or ... 
*/
int	rt_parse_cam(char *line, t_la_complete *la_complete)
{
	char	**arg;

	arg = ft_split(line, ' ');
	if (!arg)
		return (rt_error_put(ERROR_SYSTEM), 1);
	if (rt_parse_util_vector(arg[1], &la_complete->obj.cam.origin)
		|| rt_parse_util_vector(arg[2], &la_complete->obj.cam.direction))
		return (rt_parse_util_arg_free(arg), 1);
	la_complete->obj.cam.fov = rt_parse_util_atod(arg[3]);
	return (rt_parse_util_arg_free(arg), 0);
}
//	rt_debug_scene_cam_display(la_complete);
