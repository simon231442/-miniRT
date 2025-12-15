/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_multi_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:47:00 by jsurian42         #+#    #+#             */
/*   Updated: 2025/12/15 11:55:21 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_vec3	vec_mutli_scale(t_vec3 v, double scalar)
{
	t_vec3	ret;

	ret.x = v.x * scalar;
	ret.y = v.y * scalar;
	ret.z = v.z * scalar;
	ret.w = v.w * scalar;
	return (ret);
}
