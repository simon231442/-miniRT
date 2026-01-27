/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_choose_shape_intersect.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:41:43 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/27 14:42:30 by jsurian42        ###   ########.fr       */
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
