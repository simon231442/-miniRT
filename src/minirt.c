/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                            :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:19:33 by jsurian42         #+#    #+#             */
/*   Updated: 2025/12/01 11:18:21 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_la_complete	la_complete;

	if (ac != 2)
		return (rt_error_put(ERROR_USAGE), EXIT_FAILURE);
	ft_bzero(&la_complete, sizeof(t_la_complete));
	if (rt_parse(av[1], &la_complete))
		return (rt_parse_util_obj_free(&la_complete), EXIT_FAILURE);
	rt_debug_scene_all_display(&la_complete);
	if (rt_mlx_init(&mlx))
		rt_mlx_free(&mlx);
	if (rt_mlx_hook(&mlx))
		rt_mlx_free(&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
