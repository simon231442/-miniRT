/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:14:10 by jsurian42         #+#    #+#             */
/*   Updated: 2025/12/22 18:22:26 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RENDER_H
# define RT_RENDER_H

typedef struct s_render_view
{
	int	x;
	int	y;
	int	*pixel_addr;
}	t_render_view;

int	rt_render(t_la_complete *la_complete);

#endif
