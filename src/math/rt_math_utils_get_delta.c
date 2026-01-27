/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rt_math_utils_get_delta.c                          :+:      :+:    :+:   */
/*                                                      +:+                   */
/*   By: jsurian <jsurian@student.42lausanne.ch>       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/12/15 16:58:44 by jsurian        #+#    #+#                */
/*   Updated: 2026/01/27 15:34:41 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	rt_math_utils_get_delta(double a, double b, double c)
{
	return (b * b - 4 * a * c);
}
