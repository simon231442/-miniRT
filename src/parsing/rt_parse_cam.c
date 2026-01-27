/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_cam.c                                      :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:28:02 by srenaud           #+#    #+#             */
/*   Updated: 2026/01/16 15:15:46 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int arg_all_is_valid(char **arg);
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
		return (rt_error_put(ERROR_SYSTEM), 1);
	if (!arg_all_is_valid(arg))
		return (/*1*/0);
	if (rt_parse_util_vector(arg[1], &la_complete->obj.cam.origin) ||
		rt_parse_util_vector(arg[2], &la_complete->obj.cam.direction))
		return (rt_parse_util_arg_free(arg), 1);
	la_complete->obj.cam.fov = rt_parse_util_atod(arg[3]);
	return (rt_parse_util_arg_free(arg), 0);
}

static int	arg_all_is_valid(char **arg)
{
	if (ft_arg_count(arg) != 4)
		return (rt_error_put(ERROR_ARG_QUANTITY), 0);
	if (!ft_real_format_is_valid(arg[3]))
		return (rt_error_put(ERROR_REAL_NB_FORMAT), 1);
	if (!ft_real_is_in_range(arg[3],"0","180"))
	{
		printf("%s\n", arg[3]);
		return (rt_error_put(ERROR_OUT_OF_RANGE), 1);
	}
	printf("%s is ok!\n", arg[3]);
	return (1);
}

