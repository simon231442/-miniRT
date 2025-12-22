/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rt_math_sphere_discri.c                            :+:      :+:    :+:   */
/*                                                      +:+                   */
/*   By: jsurian <jsurian@student.42lausanne.ch>       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/12/15 16:58:44 by jsurian        #+#    #+#                */
/*   Updated: 2025/12/22 17:34:33 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static

double	rt_math_sphere_get_delta(double radius, t_vec3 d, t_vec3 oc)
{
	double	delta;
	double	delta1;
	double	delta2;

	//delta = {2 * dot_p(vD, vOC)}^2 - 4 * {dot_p(vD, vD) * dot_p(vOC, vOC) - r^2};
	delta1 = pow(2 * vec_dot(vD, vOC), 2);
	delta2 = 4 * {dot_p(vD, vD) * dot_p(vOC, vOC) - pow(radius, 2)};
	delta = delta1 - delta2;
	return (delta);
}
