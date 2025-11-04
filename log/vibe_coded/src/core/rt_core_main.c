/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_core_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "rt_application.h"
#include "rt_core.h"
#include "rt_error.h"

static void	rt_core_usage(void)
{
	ft_putendl_fd("Usage: ./miniRT <scene.rt>", 2);
}

int	rt_core_main(int argc, char **argv)
{
	t_context	context;

	if (argc != 2)
	{
		rt_core_usage();
		return (EXIT_FAILURE);
	}
	if (rt_core_application_start(&context, argv[1]) != 0)
	{
		rt_core_application_destroy(&context);
		return (EXIT_FAILURE);
	}
	rt_core_application_destroy(&context);
	return (EXIT_SUCCESS);
}
