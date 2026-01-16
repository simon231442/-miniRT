/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:19:33 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/16 11:16:11 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_la_complete	la_complete;

	la_complete.coefficient = 0;
	if (ac != 2)
		return (rt_error_put(ERROR_USAGE), EXIT_FAILURE);
	ft_bzero(&la_complete, sizeof(t_la_complete));
	if (rt_parse(av[1], &la_complete))
		return (rt_parse_util_shape_free(&la_complete), EXIT_FAILURE);

//	rt_debug_scene_all_display(&la_complete);

	//ajouter dans les retours les frees de la complete
	if (rt_mlx_init(&la_complete.mlx))
		return (rt_mlx_free(&la_complete.mlx),
			rt_parse_util_shape_free(&la_complete), EXIT_FAILURE);

	if (rt_render(&la_complete))
		return (rt_mlx_free(&la_complete.mlx),
			rt_parse_util_shape_free(&la_complete), EXIT_FAILURE);

	if (rt_mlx_hook(&la_complete.mlx))
		return (rt_mlx_free(&la_complete.mlx),
			rt_parse_util_shape_free(&la_complete), EXIT_FAILURE);

	mlx_loop(la_complete.mlx.mlx_ptr);
	return (0);
}
