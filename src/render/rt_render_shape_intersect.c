/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_shape_intersect.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:51:26 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/27 13:10:53 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_render_choose_shape_intersect(t_ray r, t_shape shape, double *t)
{
	if (shape.type == SPHERE) 
		return (rt_math_sphere_intersect(r, shape, t));
	if (shape.type == PLANE) 
		return (rt_math_plane_intersect(r, shape, t));
	if (shape.type == CYLINDER) 
		return (rt_math_cylinder_intersect(r, shape, t));
	return (0);
}

int	rt_render_shape_intersect(t_list *shape_lst, t_shape *last_shape, t_ray r,
		double *t_min)
{
	double	t;

	*t_min = T_MAX;
	while (shape_lst != NULL)
	{
		if (rt_render_choose_shape_intersect(r, *shape_lst->shape, &t))
		{
			if (t < *t_min)
			{
				*t_min = t;
				*last_shape = *shape_lst->shape;
			}
		}
		shape_lst = shape_lst->next;
	}
	if (*t_min < T_MAX)
		return (1);
	return (0);
}
