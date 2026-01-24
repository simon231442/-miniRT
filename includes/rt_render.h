/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:14:10 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/24 15:59:17 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RENDER_H
# define RT_RENDER_H

#define T_MAX 10000
#define EPSILON 1e-6
#define	SPHERE		0
#define	PLANE		1
#define	CYLINDER	2

typedef struct s_render_view
{
	int		x;
	int		y;
	int		*pixel_addr;
	t_vec3	pixel_vec;
}	t_render_view;


int	rt_render(t_la_complete *la_complete);
int	*rt_render_pixel_get_addr(t_mlx *mlx, int x, int y);
int	rt_render_pixel_get_color(t_list *shape, t_obj obj, t_render_view v);

int	rt_render_shape_intersect(t_list *shape_lst, t_shape *last_shape, t_ray r,
		double *t_min);


double	rt_render_light_get_intensity(t_list *shape, t_obj obj,
		t_shape *act_shape, t_ray r, double t_min);

t_color	rt_render_pixel_get_ret_color(t_color shape_color, t_ambient ambient,
			double intensity);

#endif
