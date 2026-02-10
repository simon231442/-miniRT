/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_hook_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:45:27 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/10 15:36:47 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_render.h"
//#include "stdio.h"

int	rt_mlx_hook_key(int keycode, t_la_complete *self)
{
	if (keycode == KEY_Q || keycode == KEY_ESC)
		rt_mlx_free(&self->mlx);
	else if (keycode == KEY_W)
		self->obj.light.origin.y += 0.1;
	else if (keycode == KEY_S)
		self->obj.light.origin.y -= 0.1;
	else if (keycode == KEY_D)
		self->obj.light.origin.x += 0.1;
	else if (keycode == KEY_A)
		self->obj.light.origin.x -= 0.1;
	else if (keycode == ARROW_UP)
		self->obj.light.origin.z += 0.1;
	else if (keycode == ARROW_DOWN)
		self->obj.light.origin.z -= 0.1;
	else
		return (0);
	rt_render(self);
	return (0);
}
//	printf("keycode %d\n", keycode);
