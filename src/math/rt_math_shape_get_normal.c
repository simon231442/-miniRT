/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_shape_get_normal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:49:48 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/06 13:31:38 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	rt_math_shape_get_normal(t_vec3 intersect_point, t_shape shape)
{
	if (shape.type == SPHERE)
		return (rt_math_sphere_get_normal(intersect_point, shape.origin));
	else if (shape.type == PLANE)
		return (shape.direction);
	else
		return (rt_math_cylinder_get_normal(intersect_point, shape.origin,
				shape.direction, shape.hit_type));
}
//esle cylinder
