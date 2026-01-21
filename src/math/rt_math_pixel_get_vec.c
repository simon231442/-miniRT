/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rt_math_pixel_get_vec.c                            :+:      :+:    :+:   */
/*                                                      +:+                   */
/*   By: jsurian <jsurian@student.42lausanne.ch>       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/12/15 16:45:57 by jsurian        #+#    #+#                */
/*   Updated: 2026/01/21 15:45:31 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//a changer si size_x != de size_y
t_vec3	rt_math_pixel_get_vec(int x, int y, double fov, t_vec3 direction)
{
	t_vec3	forward;
	t_vec3	world_up;
	t_vec3	right;
	t_vec3	up;

	double	nx;
	double	ny;
	double	fov_rad;
	double	d;
	t_vec3	pixel_vec;

	forward = rt_math_utils_vec_normalize(direction);
	world_up = (t_vec3){0, 1, 0};
	right = rt_math_utils_vec_normalize(
			rt_math_utils_vec_cross(forward, world_up));
	up = rt_math_utils_vec_cross(right, forward);

	nx = (x - SIZE_X/2) / (SIZE_X/2);
	ny = (SIZE_Y/2 -y) / (SIZE_Y/2);
	fov_rad = fov * M_PI / 180;
	d = 1 / tan(fov_rad / 2);
	pixel_vec = rt_math_utils_vec_add(
			rt_math_utils_vec_add(
			rt_math_utils_vec_multi_scale(forward, d),
			rt_math_utils_vec_multi_scale(right, nx)
			),
			rt_math_utils_vec_multi_scale(up, ny)
	);
	return (rt_math_utils_vec_normalize(pixel_vec));
}
