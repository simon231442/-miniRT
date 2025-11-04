/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_COLOR_H
# define RT_COLOR_H

# include "rt_structs.h"

t_color	rt_color(double r, double g, double b);
t_color	rt_color_add(t_color a, t_color b);
t_color	rt_color_scale(t_color color, double factor);
t_color	rt_color_mul(t_color a, t_color b);
t_color	rt_color_clamp(t_color color, double min, double max);
int	rt_color_to_int(t_color color);

t_color	rt_color_from_rgb(int r, int g, int b);

#endif
