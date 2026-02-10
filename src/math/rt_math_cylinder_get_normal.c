/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_cylinder_get_normal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:11:24 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/10 15:45:13 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_math.h"

t_vec3	rt_math_cylinder_get_normal(t_vec3 intersect_point,
		t_vec3 origin_cylinder, t_vec3 dir_cylinder, t_hit_type type_hit)
{
	t_vec3	op;
	double	t;
	t_vec3	c;

	if (type_hit == BODY)
	{
		dir_cylinder = rt_math_utils_vec_normalize(dir_cylinder);
		op = rt_math_utils_vec_sub(intersect_point, origin_cylinder);
		t = rt_math_utils_vec_dot(op, dir_cylinder);
		c = rt_math_utils_vec_add(origin_cylinder,
				rt_math_utils_vec_multi_scale(dir_cylinder, t));
		return (rt_math_utils_vec_sub(intersect_point, c));
	}
	else if (type_hit == TOP)
		return (dir_cylinder);
	else
		return (rt_math_utils_vec_multi_scale(dir_cylinder, -1));
}
//else bottom
