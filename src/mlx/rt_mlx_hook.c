/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:42:32 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/07 16:42:45 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_mlx_hook(t_mlx *self)
{
	mlx_key_hook(self->win_ptr, rt_mlx_hook_key, self);
	return (0);
}
	//mlx_mouse_hook(self->win_ptr, rt_mlx_hook_mouse, self);
	//mlx_hook(self->win_ptr, LITTLECROSS, 0, hook, self);
