/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rt_math_pixel_get_vec.c                            :+:      :+:    :+:   */
/*                                                      +:+                   */
/*   By: jsurian <jsurian@student.42lausanne.ch>       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/12/15 16:45:57 by jsurian        #+#    #+#                */
/*   Updated: 2026/01/27 13:17:41 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//a changer si size_x != de size_y
t_vec3	rt_math_pixel_get_vec(int x, int y, double fov, t_vec3 direction,
		t_vec3 origin)
{
	t_vec3	u_temp;
	t_vec3	up_global;
	t_vec3	t_n;
	t_vec3	b_n;
	t_vec3	v_n;

//	double	d = 1;
	double	k = SIZE_X;
	double	m = SIZE_Y;

	int i = x;
	int j = y;

	t_vec3	C; //centre viewport
	double fov_rad = fov * M_PI / 180;

	up_global.x = 0;
	up_global.y = 1;
	up_global.z = 0;
	t_n = rt_math_utils_vec_normalize(direction);
	u_temp = rt_math_utils_vec_cross(up_global, t_n);	//temporaire horizontal
	b_n = rt_math_utils_vec_normalize(u_temp);		// right vector (droite)
	v_n = rt_math_utils_vec_cross(t_n, b_n);		//up vector (haut)

	//centre viewport
	C = rt_math_utils_vec_add(origin, t_n);
	double h_x = tan(fov_rad/2) * ((m - 1) / (k - 1));
	double h_y = tan(fov_rad/2);
	t_vec3 temp = rt_math_utils_vec_sub(C, rt_math_utils_vec_multi_scale(b_n, h_x)); 
	t_vec3 P_1m = rt_math_utils_vec_sub(temp,
			rt_math_utils_vec_multi_scale(v_n, h_y)); 
	double delta_x = 2 * h_x / (k - 1);
	double delta_y = 2 * h_y / (m - 1);
	temp = rt_math_utils_vec_multi_scale(
			rt_math_utils_vec_multi_scale(b_n, delta_x), i - 1);
	t_vec3 temp2 = rt_math_utils_vec_multi_scale(
			rt_math_utils_vec_multi_scale(v_n, delta_y), m - j);
	t_vec3 P_ij = rt_math_utils_vec_add(
			P_1m, rt_math_utils_vec_add(temp, temp2));
	t_vec3 r_ij = rt_math_utils_vec_normalize(rt_math_utils_vec_sub(P_ij, origin));
	return (r_ij);
}
