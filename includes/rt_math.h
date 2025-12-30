/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:41:24 by jsurian42         #+#    #+#             */
/*   Updated: 2025/12/30 11:04:29 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
# define RT_MATH_H

int	*rt_math_get_pixel_addr(t_mlx *mlx, int x, int y);
t_vec3	rt_math_get_vec_pixel(int x, int y, double fov);

#endif
