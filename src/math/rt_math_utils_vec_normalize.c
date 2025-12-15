/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_utils_vec_normalize.c                       :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:48:05 by jsurian42         #+#    #+#             */
/*   Updated: 2025/12/15 17:03:41 by jsurian        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

//normalization uniquement de vecteurs
t_vec3	normalize(t_vec3 v)
{
	t_vec3	ret;
	double	length;

	length = vec_length(v);
	if (length == 0)
	{
		ret.x = 0;
		ret.y = 0;
		ret.z = 0;
		ret.w = 0;
		return (ret);
	}
	ret.x = v.x / length;
	ret.y = v.y / length;
	ret.z = v.z / length;
	ret.w = 0;
	return (ret);
}
