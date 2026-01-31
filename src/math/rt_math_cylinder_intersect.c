/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_cylinder_intersect.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:11:45 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/31 15:54:31 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_math_cylinder_intersect(t_ray r, t_shape cylinder, double *t)
{
	double t_min;

	t_min = T_MAX;
	if (rt_math_cylinder_intersect_body(r, cylinder, t))
		t_min = *t;
	if (rt_math_cylinder_intersect_cap(r, cylinder, t))
	{
		if (*t < t_min)
			return (1);
	}
	if (t_min != T_MAX)
	{
		*t = t_min;
		return (1);
	}
	return (0);	
}
