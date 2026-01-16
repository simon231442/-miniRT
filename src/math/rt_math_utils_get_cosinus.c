/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_utils_get_cosinus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:54:56 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/15 14:52:37 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	rt_math_utils_get_cosinus(t_vec3 normal_vec, t_vec3 light_vec)
{
	double	dot_product;

	normal_vec = rt_math_utils_vec_normalize(normal_vec);
	light_vec = rt_math_utils_vec_normalize(light_vec);
	dot_product = rt_math_utils_vec_dot(normal_vec, light_vec);
//
//	//calculer l'angles
//	angle = angle * M_PI / 180; //en radians
	return (dot_product);
}
