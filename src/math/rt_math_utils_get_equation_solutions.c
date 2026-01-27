/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_utils_get_equation_solutions.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:30:36 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/27 15:33:19 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	rt_math_utils_get_equation_solutions(double a, double b, double c,
		double sqrt_delta, int positive)
{
	if (positive)
		return ((-b + sqrt_delta) / (2 * a));
	else
		return ((-b - sqrt_delta) / (2 * a));
}
