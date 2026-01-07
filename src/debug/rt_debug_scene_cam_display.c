/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_debug_scene_cam_display.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:10:35 by srenaud           #+#    #+#             */
/*   Updated: 2026/01/07 16:34:56 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	cam_origin_display(t_la_complete *la_complete);
static void	cam_direction_display(t_la_complete *la_complete);
static void	cam_fov_display(t_la_complete *la_complete);

void	rt_debug_scene_cam_display(t_la_complete *la_complete)
{
	printf("Camera Display:\n");
	printf("--------------------------\n");
	cam_origin_display(la_complete);
	cam_direction_display(la_complete);
	cam_fov_display(la_complete);
	printf("--------------------------\n\n");
	return ;
}

static void	cam_origin_display(t_la_complete *la_complete)
{
	printf("Camera Origin: (%.2f, %.2f, %.2f)\n",
		la_complete->obj.cam.origin.x,
		la_complete->obj.cam.origin.y,
		la_complete->obj.cam.origin.z);
	return ;
}

static void	cam_direction_display(t_la_complete *la_complete)
{
	printf("Camera Direction: (%.2f, %.2f, %.2f)\n",
		la_complete->obj.cam.direction.x,
		la_complete->obj.cam.direction.y,
		la_complete->obj.cam.direction.z);
	return ;
}

static void	cam_fov_display(t_la_complete *la_complete)
{
	printf("Camera FOV: %.2f degrees\n", la_complete->obj.cam.fov);
	return ;
}
