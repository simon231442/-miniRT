/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_sphere_get_normal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:43:42 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/15 14:26:25 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//en connaissant le point d'intersection t, on peut calculer la coordonne
//avec la cooordonne du point moins lorigin de la sphere -> normal

t_vec3	rt_math_sphere_get_normal(t_vec3 intersect_point, t_vec3 origin_sphere)
{
	return (rt_math_utils_vec_sub(origin_sphere, intersect_point));
}
