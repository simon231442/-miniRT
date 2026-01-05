/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rt_math_pixel_get_vec.c                            :+:      :+:    :+:   */
/*                                                      +:+                   */
/*   By: jsurian <jsurian@student.42lausanne.ch>       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/12/15 16:45:57 by jsurian        #+#    #+#                */
/*   Updated: 2026/01/05 17:31:17 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	rt_math_pixel_get_vec(int x, int y, double fov)
{
	t_vec3	d;

	d.x = x - SIZE_X / 2;
	d.y = SIZE_Y / 2 - y;
	d.z = - SIZE_Y / 2 / tan(fov / 2);
	d = rt_math_utils_vec_normalize(d);
	return (d);
}
