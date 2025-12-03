/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_ambient.c                                  :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:28:17 by srenaud           #+#    #+#             */
/*   Updated: 2025/11/21 11:43:33 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/** 
 * @brief	parse an ambient ligthing line and fill la_complete->obj.ambient
 			ambient ligthing's parametres : ratio, color 
 * @return	0 on success, ERROR_SYSTEM or ... 
*/

int rt_parse_ambient(char *line, t_la_complete *la_complete)
{
	char	**arg;

	arg = ft_split(line, ' ');
	if (!arg)
		return (rt_error_put(ERROR_SYSTEM), 1);
	la_complete->obj.ambient.ratio = rt_parse_atod(arg[1]);
	if (rt_parse_color(arg[2], &la_complete->obj.ambient.color))
		return (rt_parse_util_arg_free(arg), 1);
	return (rt_parse_util_arg_free(arg), 0);
}
