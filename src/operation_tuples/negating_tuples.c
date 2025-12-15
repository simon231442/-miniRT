/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negating_tuples.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:47:33 by jsurian42         #+#    #+#             */
/*   Updated: 2025/12/15 11:39:28 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_vec3	negating_tuples(t_vec3 v)
{
	t_vec3	ret;

	ret.x = 0 - v.x;
	ret.y = 0 - v.y;
	ret.z = 0 - v.z;
	ret.w = 0 - v.w;
	return (ret);
}
