/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:29:13 by srenaud           #+#    #+#             */
/*   Updated: 2026/02/10 15:29:29 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_parsing.h"
#include "rt_error.h"

/** 
 * @brief	parse a light line and fill la_complete->obj.light
 			light's parametres : origin, ratio, color 
 * @return	0 on success, ERROR_SYSTEM or ... 
*/
static int	arg_all_is_valid(char **arg);

int	rt_parse_light(char *line, t_la_complete *la_complete)
{
	char	**arg;

	arg = ft_split(line, ' ');
	if (!arg)
		return (rt_error_put(ERROR_SYSTEM), 1);
	if (!arg_all_is_valid(arg))
		return (rt_parse_util_arg_free(arg), 1);
	if (rt_parse_util_vector(arg[1], &la_complete->obj.light.origin))
		return (rt_parse_util_arg_free(arg), 1);
	la_complete->obj.light.ratio = rt_parse_util_atod(arg[2]);
	return (rt_parse_util_arg_free(arg), 0);
}

static int	arg_all_is_valid(char **arg)
{
	if (ft_arg_count(arg) != 3)
		return (rt_error_put(ERROR_ARG_QUANTITY), 0);
	if (!ft_real_format_is_valid(arg[2]))
		return (rt_error_put(ERROR_REAL_NB_FORMAT), 0);
	if (!ft_real_is_in_range(arg[2], "0", "1"))
		return (rt_error_put(ERROR_OUT_OF_RANGE), 0);
	return (1);
}
