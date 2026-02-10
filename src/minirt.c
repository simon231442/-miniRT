/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:19:33 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/10 15:25:19 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_error.h"
#include "rt_parsing.h"
#include "rt_math.h"
#include "rt_render.h"

int	is_rt_file(char *file_name);

int	main(int ac, char **av)
{
	t_la_complete	la_complete;

	if (ac != 2)
		return (rt_error_put(ERROR_USAGE), EXIT_FAILURE);
	if (!is_rt_file(av[1]))
		return (rt_error_put(ERROR_FILE_NAME), EXIT_FAILURE);
	ft_bzero(&la_complete, sizeof(t_la_complete));
	if (rt_parse(av[1], &la_complete))
		return (rt_parse_util_shape_free(&la_complete), EXIT_FAILURE);
	rt_math_cam_calculation(&la_complete.obj.cam);
	if (rt_mlx_init(&la_complete.mlx))
		return (rt_mlx_free(&la_complete.mlx),
			rt_parse_util_shape_free(&la_complete), EXIT_FAILURE);
	if (rt_render(&la_complete))
		return (rt_mlx_free(&la_complete.mlx),
			rt_parse_util_shape_free(&la_complete), EXIT_FAILURE);
	if (rt_mlx_hook(&la_complete))
		return (rt_mlx_free(&la_complete.mlx),
			rt_parse_util_shape_free(&la_complete), EXIT_FAILURE);
	mlx_loop(la_complete.mlx.mlx_ptr);
	return (0);
}

int	is_rt_file(char *file_name)
{
	char	*word_ptr;

	word_ptr = ft_strrchr(file_name, '.');
	if (word_ptr
		&& word_ptr[1] && word_ptr[1] == 'r'
		&& word_ptr[2] && word_ptr[2] == 't'
		&& !word_ptr[3])
		return (1);
	return (0);
}
