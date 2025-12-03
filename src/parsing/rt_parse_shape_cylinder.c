/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_shape_cylinder.c                           :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:30:38 by srenaud           #+#    #+#             */
/*   Updated: 2025/11/21 11:51:21 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/** 
 * @brief	parse a cylinder line, create a shape node and fill it's fields
 			cylinder parametres : origine, radius, height, color 
 * @return	0 on success, ERROR_SYSTEM or ... 
*/

static t_shape	*shape_cylinder_new(char *line);

int rt_parse_shape_cylinder(char *line, t_la_complete *la_complete)
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
		return (rt_error_put(ERROR_SYSTEM), NULL);
	shape->type = CYLINDER;
	if (rt_parse_util_vector(arg[1], &shape->origin))
		return (free(shape), rt_parse_util_arg_free(arg), NULL);
	if (rt_parse_util_vector(arg[2], &shape->direction))
		return (free(shape), rt_parse_util_arg_free(arg), NULL);
	shape->radius = rt_parse_util_atod(arg[3]) / 2;
	shape->height = rt_parse_util_atod(arg[4]);
	if (rt_parse_util_color(arg[5], &shape->color))
		return (free(shape), rt_parse_util_arg_free(arg), NULL);
	return (shape);
}
