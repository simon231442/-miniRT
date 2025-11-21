/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                            :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:19:33 by jsurian42         #+#    #+#             */
/*   Updated: 2025/11/21 15:42:50 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	(void)av;

	if (ac != 2)
		return (rt_error_put(ERROR_USAGE));

	if (rt_mlx_init(&mlx))
		rt_mlx_free(&mlx);
	if (rt_mlx_hook(&mlx))
		rt_mlx_free(&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
