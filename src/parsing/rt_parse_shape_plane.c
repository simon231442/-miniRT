/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_shape_plane.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:30:17 by srenaud           #+#    #+#             */
/*   Updated: 2026/01/07 16:47:42 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/** 
 * @brief	parse an plane line, create a shape node and fill it's fields
 			plane parametres : origine, direction, color 
 * @return	0 on success, ERROR_SYSTEM or ... 
*/

static t_shape	*shape_plane_new(char *line);

int	rt_parse_shape_plane(char *line, t_la_complete *la_complete)
{
	t_list	*lst;
	t_shape	*shape;

	shape = shape_plane_new(line);
	if (!shape)
		return (1);
	lst = ft_lstnew(shape);
	if (!lst)
		return (free(shape), rt_error_put(ERROR_SYSTEM), 1);
	ft_lstadd_back(&la_complete->shape, lst);
	return (0);
}

static t_shape	*shape_plane_new(char *line)
{
	t_shape	*shape;
	char	**arg;

	shape = malloc(sizeof(t_shape));
	if (!shape)
		return (rt_error_put(ERROR_SYSTEM), NULL);
	arg = ft_split(line, ' ');
	if (!arg)
		return (rt_error_put(ERROR_SYSTEM), NULL);
	shape->type = PLANE;
	if (rt_parse_util_vector(arg[1], &shape->origin))
		return (free(shape), rt_parse_util_arg_free(arg), NULL);
	if (rt_parse_util_vector(arg[2], &shape->direction))
		return (free(shape), rt_parse_util_arg_free(arg), NULL);
	if (rt_parse_util_color(arg[3], &shape->color))
		return (free(shape), rt_parse_util_arg_free(arg), NULL);
	return (shape);
}
