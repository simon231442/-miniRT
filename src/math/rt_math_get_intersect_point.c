/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_get_intersect_point.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:13:43 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/16 13:57:14 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	rt_math_get_intersect_point(t_ray r, double t_min)
{
	t_vec3	intersect_point;

	intersect_point.x = r.dir.x * t_min + r.origin.x;
	intersect_point.y = r.dir.y * t_min + r.origin.y;
	intersect_point.z = r.dir.z * t_min + r.origin.z;
	intersect_point.w = 1; //point
	return (intersect_point);
}
