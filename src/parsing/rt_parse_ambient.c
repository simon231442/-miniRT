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

static int	arg_all_is_valid(char **arg);

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
	if (!arg_all_is_valid(arg))
	{
		//return (1);
	}
	la_complete->obj.ambient.ratio = rt_parse_util_atod(arg[1]);
	if (rt_parse_util_color(arg[2], &la_complete->obj.ambient.color))
	{
		//return (rt_parse_util_arg_free(arg), 1);
	}
	return (rt_parse_util_arg_free(arg), 0);
}

static int	arg_all_is_valid(char **arg)
{
	if (ft_arg_count(arg) != 3)
		return (rt_error_put(ERROR_ARG_QUANTITY), 0);
	if (!ft_real_format_is_valid(arg[1]))
		return (rt_error_put(ERROR_REAL_NB_FORMAT), 0);
	if (!ft_real_is_in_range(arg[1],"0","1"))
	{
		printf("hum hum %s\n", arg[1]);
		return (rt_error_put(ERROR_OUT_OF_RANGE), 0);
	}
	printf("%s is valid\n", arg[1]);
	return (1);
}

