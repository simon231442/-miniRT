/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rt_math_sphere_discri.c                             :+:    :+:           */
/*                                                      +:+                   */
/*   By: jsurian <jsurian@student.42lausanne.ch>       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/12/15 16:58:44 by jsurian        #+#    #+#                */
/*   Updated: 2025/12/15 17:17:23 by jsurian        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

double	rt_math_sphere_get_delta(double radius, t_vec3 d, t_vec3 oc)
{
	double	delta;
	double	delta1;
	double	delta2;

//delta = {2 * dot_p(vD, vOC)}^2 - 4 * {dot_p(vD, vD) * dot_p(vOC, vOC) - r^2};
	delta1 = {2 * dot_p(vD, vOC)}^2;
	delta2 = 4 * {dot_p(vD, vD) * dot_p(vOC, vOC) - r^2};
	delta = delta1 - delta2;
	return (delta);
}
