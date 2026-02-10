/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_debug_scene_all_display.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:58:57 by srenaud           #+#    #+#             */
/*   Updated: 2026/02/10 15:50:55 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_debug.h"

void	rt_debug_scene_all_display(t_la_complete *la_complete)
{
	rt_debug_scene_cam_display(la_complete);
	rt_debug_scene_light_display(la_complete);
	rt_debug_scene_shape_display(la_complete);
}
