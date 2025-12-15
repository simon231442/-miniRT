/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rt_math_vec_pixel.c                                 :+:    :+:           */
/*                                                      +:+                   */
/*   By: jsurian <jsurian@student.42lausanne.ch>       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/12/15 16:45:57 by jsurian        #+#    #+#                */
/*   Updated: 2025/12/15 16:58:21 by jsurian        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_vec3	rt_math_vec_pixel(int x, int y, double fov)
{
	t_vec3	d;

	d.x = x - SIZE_X / 2;
	d.y = SIZE_Y / 2 - y;
	d.z = - SIZE_Y / 2 / tan(fov / 2);
	d = normalize(d);
	return (d);
}
