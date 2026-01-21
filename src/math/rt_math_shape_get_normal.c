/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_shape_get_normal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:49:48 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/21 12:05:34 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	rt_math_shape_get_normal(t_vec3 intersect_point, t_shape *shape)
{
	t_vec3	ret;
	if (shape->type == SPHERE)
		return (rt_math_sphere_get_normal(intersect_point, shape->origin));
	else if (shape->type == PLANE)
		return (shape->direction);
	else if (shape->type == CYLINDER)
		return (rt_math_cylinder_get_normal());
	return (ret); //??????????????
}
