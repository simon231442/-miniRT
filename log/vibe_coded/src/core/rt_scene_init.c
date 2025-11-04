/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_scene.h"
#include "rt_color.h"
#include "libft.h"

void	rt_scene_init(t_scene *scene)
{
	if (scene == NULL)
		return ;
	ft_bzero(scene, sizeof(t_scene));
	scene->ambient.color = rt_color(0.0, 0.0, 0.0);
	scene->ambient.ratio = 0.0;
}

void	rt_scene_destroy(t_scene *scene)
{
	if (scene == NULL)
		return ;
	ft_bzero(scene, sizeof(t_scene));
}
