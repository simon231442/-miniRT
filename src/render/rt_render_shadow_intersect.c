/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_shadow_intersect.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:33:30 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/26 17:00:02 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_render_shadow_intersect(t_list *shape_lst, t_ray r, double light_distance)
{
	double	t;

	while (shape_lst != NULL)
	{
		if (rt_render_choose_shape_intersect(r, *shape_lst->shape, &t))
		{
			if (t < light_distance) ///utils ???????
				return (1);
		}
		shape_lst = shape_lst->next;
	}
	return (0);
}
