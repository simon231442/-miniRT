/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_plane_intersect.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:06:24 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/06 14:55:29 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//plane.direction -> normal du plan
int	rt_math_plane_intersect(t_ray r, t_shape plane, double *t)
{
	double	denom;
	t_vec3	temp;

	denom = rt_math_utils_vec_dot(plane.direction, r.dir);
	if (denom != 0)
	{
		temp = rt_math_utils_vec_sub(plane.origin, r.origin);
		*t = rt_math_utils_vec_dot(temp, plane.direction) / denom;
		if (*t > EPSILON)
			return (1);
	}
	return (0);
}
