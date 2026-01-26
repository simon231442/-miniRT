/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_light_get_vec.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 18:30:21 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/26 16:13:36 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	rt_math_light_get_vec(t_vec3 intersect_point, t_vec3 light_origin)
{
	t_vec3	ret;

	ret = rt_math_utils_vec_sub(light_origin, intersect_point);
	ret = rt_math_utils_vec_normalize(ret);
	return (ret);
}
