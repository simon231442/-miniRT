/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rt_math_pixel_get_vec.c                            :+:      :+:    :+:   */
/*                                                      +:+                   */
/*   By: jsurian <jsurian@student.42lausanne.ch>       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/12/15 16:45:57 by jsurian        #+#    #+#                */
/*   Updated: 2026/01/29 17:11:14 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//a changer si size_x != de size_y
/**/
t_vec3	rt_math_pixel_get_vec(int i, int j, t_cam cam)
{
	t_vec3	direction_ij;

	direction_ij.x = cam.first_pixel.x
		+ i * cam.right.x * cam.width / SIZE_X
		- j * cam.up.x * cam.height / SIZE_Y - cam.origin.x;
	direction_ij.y = cam.first_pixel.y
		+ i * cam.right.y * cam.width / SIZE_X
		- j * cam.up.y * cam.height / SIZE_Y - cam.origin.y;
	direction_ij.z = cam.first_pixel.z
		+ i * cam.right.z * cam.width / SIZE_X
		- j * cam.up.z * cam.height / SIZE_Y - cam.origin.z;
	direction_ij = rt_math_utils_vec_normalize(direction_ij);
	return (direction_ij);
}
