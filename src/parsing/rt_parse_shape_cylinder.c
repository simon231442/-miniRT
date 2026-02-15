/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_shape_cylinder.c                           :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:30:38 by srenaud           #+#    #+#             */
/*   Updated: 2026/02/15 14:38:22 by jsurian        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_parsing.h"
#include "rt_error.h"

/** 
 * @brief	parse a cylinder line, create a shape node and fill it's fields
 			cylinder parametres : origine, radius, height, color 
 * @return	0 on success, ERROR_SYSTEM or ... 
*/

static t_shape	*shape_cylinder_new(char *line);
static int		arg_all_is_valid(char **arg);

int	rt_parse_shape_cylinder(char *line, t_la_complete *la_complete)
{
	t_list	*lst;
	t_shape	*shape;

	shape = shape_cylinder_new(line);
	if (!shape)
		return (1);
	lst = ft_lstnew(shape);
	if (!lst)
		return (free(shape), rt_error_put(ERROR_SYSTEM), 1);
	ft_lstadd_back(&la_complete->shape, lst);
	return (0);
}

static t_shape	*shape_cylinder_new(char *line)
{
	t_shape	*shape;
	char	**arg;

	shape = malloc(sizeof(t_shape));
	if (!shape)
		return (rt_error_put(ERROR_SYSTEM), NULL);
	arg = ft_split(line, ' ');
	if (!arg)
		return (free(shape), rt_error_put(ERROR_SYSTEM), NULL);
	if (!arg_all_is_valid(arg))
		return (free(shape), rt_parse_util_arg_free(arg), NULL);
	shape->type = CYLINDER;
	if (rt_parse_util_vector(arg[1], &shape->origin))
		return (free(shape), rt_parse_util_arg_free(arg), NULL);
	if (rt_parse_util_vector(arg[2], &shape->direction))
		return (free(shape), rt_parse_util_arg_free(arg), NULL);
	shape->radius = rt_parse_util_atod(arg[3]) / 2;
	shape->height = rt_parse_util_atod(arg[4]);
	if (rt_parse_util_color(arg[5], &shape->color))
		return (free(shape), rt_parse_util_arg_free(arg), NULL);
	return (rt_parse_util_arg_free(arg), shape);
}

static int	arg_all_is_valid(char **arg)
{
	if (ft_arg_count(arg) != 6)
		return (rt_error_put(ERROR_ARG_QUANTITY), 0);
	if (!ft_real_format_is_valid(arg[3]))
		return (rt_error_put(ERROR_REAL_NB_FORMAT), 0);
	if (!ft_real_is_in_range(arg[3], "0", "214748364"))
		return (rt_error_put(ERROR_OUT_OF_RANGE), 0);
	if (!ft_real_format_is_valid(arg[4]))
		return (rt_error_put(ERROR_REAL_NB_FORMAT), 0);
	if (!ft_real_is_in_range(arg[4], "0", "214748364"))
		return (rt_error_put(ERROR_OUT_OF_RANGE), 0);
	return (1);
}
