/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_pixel_get_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:24:26 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/06 12:46:21 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#define T_MAX 10000

int	rt_render_pixel_get_color(t_la_complete *la_complete, t_render_view v)
{
	t_ray	r;
	t_list	*shape_lst;
	double	t;
	double	t_min = T_MAX;
	int		hit;

	r.dir = v.pixel_vec;
	r.origin = la_complete->obj.cam.origin;
	shape_lst = la_complete->shape;
	t = 0;
	hit = 0;
	while (shape_lst != NULL)
	{
		if (rt_math_sphere_intersect(r, la_complete->shape->shape, &t)) //si sphere
		{
			if (t < t_min)
			{
				t_min = t;
				hit = 1;
			}
		}
		shape_lst = shape_lst->next;
	}
	if (hit)
		return (0x000FF);
	else
		return (0xFFF000);
}


//	R = o + t * D
//	o : origine camera
//	t : distance
//	D : vecteur
