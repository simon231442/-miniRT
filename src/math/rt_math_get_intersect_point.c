/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_get_intersect_point.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:13:43 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/15 15:56:40 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	rt_math_get_intersect_point(t_vec3 pixel_vec, double t_min)
{
	t_vec3	intersect_point;

	intersect_point.x = pixel_vec.x * t_min;
	intersect_point.y = pixel_vec.y * t_min;
	intersect_point.z = pixel_vec.z * t_min;
	intersect_point.w = 1; //point
	return (intersect_point);
}
