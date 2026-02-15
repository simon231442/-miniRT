/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_hook.c                                       :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:42:32 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/15 13:37:24 by jsurian        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_parsing.h"

int	hook_littlecross(t_la_complete *self)
{
	rt_parse_util_shape_free(self);
	rt_mlx_free(&self->mlx);
	exit(0);
	return (1);
}

int	rt_mlx_hook(t_la_complete *self)
{
	mlx_key_hook(self->mlx.win_ptr, rt_mlx_hook_key, self);
	mlx_hook(self->mlx.win_ptr, LITTLECROSS, 0, hook_littlecross, self);
	return (0);
}

	//mlx_mouse_hook(self->win_ptr, rt_mlx_hook_mouse, self);
