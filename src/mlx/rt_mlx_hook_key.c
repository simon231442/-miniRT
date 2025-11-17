/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx_hook_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:45:27 by jsurian42         #+#    #+#             */
/*   Updated: 2025/11/17 13:00:34 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
//#include "stdio.h"

int	rt_mlx_hook_key(int keycode, t_mlx *self)
{
	if (keycode == KEY_Q)
		rt_mlx_free(self);
	//printf("keycode %d\n", keycode);
	return (0);
}
