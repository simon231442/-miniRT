/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_intersect.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_INTERSECT_H
# define RT_INTERSECT_H

# include "rt_structs.h"

int	rt_intersect_scene(const t_scene *scene, t_ray ray, t_hit *hit);
int	rt_intersect_sphere(const t_sphere *sphere, t_ray ray, t_hit *hit);
int	rt_intersect_plane(const t_plane *plane, t_ray ray, t_hit *hit);
int	rt_intersect_cylinder(const t_cylinder *cylinder, t_ray ray, t_hit *hit);

#endif
