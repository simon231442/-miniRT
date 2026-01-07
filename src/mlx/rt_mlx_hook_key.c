/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_hook_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:45:27 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/07 16:42:21 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
//#include "stdio.h"

int	rt_mlx_hook_key(int keycode, t_mlx *self)
{
	if (keycode == KEY_Q)
		rt_mlx_free(self);
	return (0);
}
	//printf("keycode %d\n", keycode);
