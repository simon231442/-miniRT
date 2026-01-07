/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:14:10 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/07 14:43:38 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RENDER_H
# define RT_RENDER_H

#define T_MAX 10000

typedef struct s_render_view
{
	int		x;
	int		y;
	int		*pixel_addr;
	t_vec3	pixel_vec;
}	t_render_view;

int	rt_render(t_la_complete *la_complete);
int	rt_render_pixel_get_color(t_la_complete *la_complete, t_render_view v);

#endif
