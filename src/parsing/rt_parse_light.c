/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:29:13 by srenaud           #+#    #+#             */
/*   Updated: 2026/01/07 16:46:14 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/** 
 * @brief	parse a light line and fill la_complete->obj.light
 			light's parametres : origin, ratio, color 
 * @return	0 on success, ERROR_SYSTEM or ... 
*/

int	rt_parse_light(char *line, t_la_complete *la_complete)
{
	char	**arg;

	arg = ft_split(line, ' ');
	if (!arg)
		return (rt_error_put(ERROR_SYSTEM), 1);
	if (rt_parse_util_vector(arg[1], &la_complete->obj.light.origin))
		return (rt_parse_util_arg_free(arg), 1);
	la_complete->obj.light.ratio = rt_parse_util_atod(arg[2]);
	if (rt_parse_util_color(arg[3], &la_complete->obj.light.color))
		return (rt_parse_util_arg_free(arg), 1);
	return (rt_parse_util_arg_free(arg), 0);
}
