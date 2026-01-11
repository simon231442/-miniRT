/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_pixel_get_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:24:26 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/09 13:18:16 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_render_pixel_get_color(t_la_complete *la_complete, t_render_view v)
{
	t_ray	r;
	t_list	*shape_lst;
	double	t;
	double	t_min;

	r.dir = v.pixel_vec;
	r.origin = la_complete->obj.cam.origin;
	shape_lst = la_complete->shape;
	t_min = T_MAX;
	while (shape_lst != NULL)
	{
		if (rt_math_sphere_intersect(r, shape_lst->shape, &t))
		{
			if (t < t_min)
			{
				t_min = t;
			}
		}
		shape_lst = shape_lst->next;
	}
	if (t_min < T_MAX)
		return (0xFF0000);
	return (0x000000);
}
