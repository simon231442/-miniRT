/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_utils_get_equation_solutions.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:30:36 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/07 16:57:08 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	rt_math_utils_get_equation_solutions(t_intersect_view v, int positive)
{
	if (positive)
		return ((-v.b + v.sqrt_delta) / (2 * v.a));
	else
		return ((-v.b - v.sqrt_delta) / (2 * v.a));
}
