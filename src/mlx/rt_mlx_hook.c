/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:42:32 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/03 12:35:41 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hook_littlecross(t_mlx *self)
{
	(void)self;
	return (1);
}

int	rt_mlx_hook(t_la_complete *self)
{
	mlx_key_hook(self->mlx.win_ptr, rt_mlx_hook_key, self);
///	if (mlx_hook(self->win_ptr, LITTLECROSS, 0, hook_littlecross, self))
///		return (1);
	return (0);
}
	//mlx_mouse_hook(self->win_ptr, rt_mlx_hook_mouse, self);
