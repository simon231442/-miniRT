/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_utils_point_distance.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:44:46 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/26 16:50:45 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/////// d = √[(x₂ - x₁)² + (y₂ - y₁)² + (z₂ - z₁)²]	
double	rt_math_utils_point_distance(t_vec3 p1, t_vec3 p2)
{
	double	d;

	d = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2) +
			pow((p2.z - p1.z), 2));
	return (d);
}
