/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rt_math_sphere_get_delta.c                         :+:      :+:    :+:   */
/*                                                      +:+                   */
/*   By: jsurian <jsurian@student.42lausanne.ch>       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/12/15 16:58:44 by jsurian        #+#    #+#                */
/*   Updated: 2026/01/07 16:38:41 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//double	rt_math_sphere_get_delta(double radius, t_vec3 d, t_vec3 oc)
//{
//	double	delta;
//	double	delta1;
//	double	delta2;
//
//	//delta = {2 * dot_p(vD, vOC)}^2 - 4 * {dot_p(vD, vD) *
	//	dot_p(vOC, vOC) - r^2};
//	delta1 = pow(2 * rt_math_utils_vec_dot(d, oc), 2);
//	delta2 = 4 * (rt_math_utils_vec_dot(d, d) *
//		rt_math_utils_vec_dot(oc, oc) - pow(radius, 2));
//	delta = delta1 - delta2;
//	return (delta);
//}
