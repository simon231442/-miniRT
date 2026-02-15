/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_shape_sphere.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:29:43 by srenaud           #+#    #+#             */
/*   Updated: 2026/02/10 15:30:56 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_parsing.h"
#include "rt_error.h"

/** 
 * @brief	parse an sphere line, create a shape node and fill it's fields
 			sphere parametres : origine, radius, color 
 * @return	0 on success, ERROR_SYSTEM or ... 
*/

static t_shape	*shape_sphere_new(char *line);
static int		arg_all_is_valid(char **arg);

int	rt_parse_shape_sphere(char *line, t_la_complete *la_complete)
{
	t_list	*lst;
	t_shape	*shape;

	shape = shape_sphere_new(line);
	if (!shape)
		return (1);
	lst = ft_lstnew(shape);
	if (!lst)
		return (free(shape), rt_error_put(ERROR_SYSTEM), 1);
	ft_lstadd_back(&la_complete->shape, lst);
	return (0);
}

static t_shape	*shape_sphere_new(char *line)
{
	t_shape	*shape;
	char	**arg;

	shape = malloc(sizeof(t_shape));
	if (!shape)
		return (rt_error_put(ERROR_SYSTEM), NULL);
	arg = ft_split(line, ' ');
	if (!arg)
		return (rt_error_put(ERROR_SYSTEM), NULL);
	if (!arg_all_is_valid(arg))
		return (rt_parse_util_arg_free(arg), NULL);
	shape->type = SPHERE;
	if (rt_parse_util_vector(arg[1], &shape->origin))
		return (free(shape), rt_parse_util_arg_free(arg), NULL);
	shape->radius = rt_parse_util_atod(arg[2]) / 2;
	if (rt_parse_util_color(arg[3], &shape->color))
		return (free(shape), rt_parse_util_arg_free(arg), NULL);
	return (rt_parse_util_arg_free(arg), shape);
}

static int	arg_all_is_valid(char **arg)
{
	if (ft_arg_count(arg) != 4)
		return (rt_error_put(ERROR_ARG_QUANTITY), 0);
	if (!ft_real_format_is_valid(arg[2]))
		return (rt_error_put(ERROR_REAL_NB_FORMAT), 0);
	if (!ft_real_is_in_range(arg[2], "-214748364", "214748364"))
		return (rt_error_put(ERROR_OUT_OF_RANGE), 0);
	return (1);
}
