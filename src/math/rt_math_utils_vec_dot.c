/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:46:01 by jsurian42         #+#    #+#             */
/*   Updated: 2025/12/15 12:10:27 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

//mesure a quel point 2 vecteurs vont dans la meme direction
//1 meme direction
//0 perpendiculaire
//-1 direction oppose
double	vec_dot(t_vec3 v1, t_vec3 v2)
{
	double	ret;

	ret = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (ret);
}
