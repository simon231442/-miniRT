/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_debug_scene_ambient_display.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:22:18 by srenaud           #+#    #+#             */
/*   Updated: 2025/12/01 16:22:18 by srenaud          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_debug_scene_ambient_display(t_la_complete *la_complete)
{
	printf("Ambient Display:\n");
	printf("--------------------------\n");
	printf("Ratio: %.2f\n", la_complete->obj.ambient.ratio);
	printf("Color: (R: %.2f, G: %.2f, B: %.2f)\n",
		la_complete->obj.ambient.color.r,
		la_complete->obj.ambient.color.g,
		la_complete->obj.ambient.color.b);
	printf("--------------------------\n\n");
	return ;
}