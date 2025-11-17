/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 08:50:41 by jsurian42         #+#    #+#             */
/*   Updated: 2025/11/17 14:03:39 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_mlx_free(t_mlx *self) //t_general
{
	if (self->img_ptr)
		mlx_destroy_image(self->mlx_ptr, self->img_ptr);
	if (self->win_ptr)
		mlx_destroy_window(self->mlx_ptr, self->win_ptr);
//	if (self->mlx_ptr)
//	{
		mlx_destroy_display(self->mlx_ptr);
		free(self->mlx_ptr);
//	}
	exit(EXIT_SUCCESS); //a modifier //exit status
}

int	rt_mlx_init(t_mlx *self)
{
	self->mlx_ptr = mlx_init();
	if (self->mlx_ptr == NULL)
		return (1);
	self->win_ptr = mlx_new_window(self->mlx_ptr, SIZE_X, SIZE_Y, TITLE);
	if (self->win_ptr == NULL)
		return (rt_mlx_free(self), 1);
	self->img_ptr = mlx_new_image(self->mlx_ptr, SIZE_X, SIZE_Y);
	if (self->img_ptr == NULL)
		return (rt_mlx_free(self), 1);
	self->img_addr = mlx_get_data_addr(self->img_ptr, &self->img_bpp,
			&self->img_line, &self->img_endian);
	if (self->img_addr == NULL)
		return (rt_mlx_free(self), 1);
	return (0);
}
