/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:05:45 by srenaud           #+#    #+#             */
/*   Updated: 2025/12/01 15:05:45 by srenaud          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DEBUG_H
# define RT_DEBUG_H

void	rt_debug_scene_all_display(t_la_complete *la_complete);
void	rt_debug_scene_cam_display(t_la_complete *la_complete);
void	rt_debug_scene_ambient_display(t_la_complete *la_complete);
void	rt_debug_scene_light_display(t_la_complete *la_complete);
void	rt_debug_scene_shape_display(t_la_complete *la_complete);

#endif
