/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:46:33 by jsurian42         #+#    #+#             */
/*   Updated: 2025/12/15 13:53:39 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

//magnitude
//pas possible de calculer celle d'un point geometriquement
//uniquement vecteur dans le cadre minirt
double	vec_length(t_vec3 v)
{
	double	ret;

	ret = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (ret);
}
