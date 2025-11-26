/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_obj_sphere.c                               :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:29:43 by srenaud           #+#    #+#             */
/*   Updated: 2025/11/21 11:49:24 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/** 
 * @brief	parse an sphere line, create a shape node and fill it's fields
 			sphere parametres : origine, radius, color 
 * @return	0 on success, ERROR_SYSTEM or ... 
*/

t_shape	*shape_sphere_new(char *line);

int rt_parse_sphere(char *line, t_la_complete *la_complete)
{
	t_list	*lst;
	t_shape	*shape;

	shape = shape_sphere_new(line);
	if (!shape)
		return (1);
	lst = ft_lstnew(shape);
	if (!lst)
		return (rt_error_put(ERROR_SYSTEM), 1);		
	ft_lstadd_back(&la_complete->shape, lst);
	return (0);
}

t_shape	*shape_sphere_new(char *line)
{
	t_shape	*shape;
	char	**arg;

	shape = malloc(sizeof(t_shape));
	if (!shape)
		return (rt_error_put(ERROR_SYSTEM), NULL);		
	arg = ft_split(line, ' ');
	if (!arg)
		return (rt_error_put(ERROR_SYSTEM), NULL);
	shape->type = SPHERE;
	if (rt_parse_vector(arg[1], &shape->origin))
		return (rt_parse_util_arg_free(arg), NULL);
	shape->radius = rt_parse_atod(arg[2]) / 2;
	if (rt_parse_color(arg[3], &shape->color))
		return (rt_parse_util_arg_free(arg), NULL);
	return (shape);
}
