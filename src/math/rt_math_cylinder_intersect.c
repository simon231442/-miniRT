/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_cylinder_intersect.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:11:45 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/06 14:46:03 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_math_cylinder_intersect(t_ray r, t_shape *cylinder, double *t)
{
	double	t_temp;
	t_shape	temp_cyl;

	*t = T_MAX;
	if (rt_math_cylinder_intersect_body(r, *cylinder, &t_temp))
	{
		if (t_temp < *t)
		{
			*t = t_temp;
			cylinder->hit_type = BODY;
		}
	}
	temp_cyl = *cylinder;
	if (rt_math_cylinder_intersect_cap(r, &temp_cyl, &t_temp))
	{
		if (t_temp < *t)
		{
			*t = t_temp;
			cylinder->hit_type = temp_cyl.hit_type;
		}
	}
	if (*t != T_MAX)
		return (1);
	return (0);
}
