/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_shadow_intersect.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:33:30 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/10 15:48:36 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_render.h"

int	rt_render_shadow_intersect(t_list *shape_lst, t_shape **last_shape, t_ray r,
		double light_distance)
{
	double	t;

	while (shape_lst != NULL)
	{
		if (*last_shape == shape_lst->shape)
		{
			shape_lst = shape_lst->next;
			continue ;
		}
		if (rt_render_choose_shape_intersect(r, shape_lst->shape, &t))
		{
			if (t < light_distance)
				return (1);
		}
		shape_lst = shape_lst->next;
	}
	return (0);
}
