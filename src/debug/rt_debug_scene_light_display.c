/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_debug_scene_light_display.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:11:42 by srenaud           #+#    #+#             */
/*   Updated: 2025/12/01 15:11:42 by srenaud          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_debug_scene_light_display(t_la_complete *la_complete)
{
    printf("Light Display:\n");
    printf("--------------------------\n");
    printf("Origin: (%.2f, %.2f, %.2f)\n",
        la_complete->obj.light.origin.x,
        la_complete->obj.light.origin.y,
        la_complete->obj.light.origin.z);
    printf("Color: (R: %.2f, G: %.2f, B: %.2f)\n",
        la_complete->obj.light.color.r,
        la_complete->obj.light.color.g,
        la_complete->obj.light.color.b);
    printf("Ratio: %.2f\n", la_complete->obj.light.ratio);
    printf("--------------------------\n\n");
    return ;
}