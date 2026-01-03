/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:12:01 by jsurian42         #+#    #+#             */
/*   Updated: 2025/12/30 14:26:55 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_render(t_la_complete *la_complete)
{
	t_render_view	v;

	if (la_complete->mlx.mlx_ptr)
	{
		v.y = 0;
		while (v.y < SIZE_Y)
		{
			v.x = 0;
			while (v.x < SIZE_X)
			{
				v.pixel_addr = rt_math_get_pixel_addr(&la_complete->mlx,
					v.x, v.y);
				v.pixel_vec = rt_math_get_vec_pixel(v.x, v.y,
					la_complete->obj.cam.fov);
				*v.pixel_addr = rt_render_get_pixel_color(la_complete, v);
				v.x++;
			}
			v.y++;
		}
	}
	mlx_put_image_to_window(la_complete->mlx.mlx_ptr,
		la_complete->mlx.win_ptr, la_complete->mlx.img_ptr, 0, 0);
	return (0);
}
