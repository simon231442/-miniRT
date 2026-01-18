/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_utils_get_int_color.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:39:04 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/18 13:51:02 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_parse_utils_get_int_color(t_color color)
{
	int	int_color;

	int_color = ((int)color.r << 16) | ((int)color.g << 8) | (int)color.b;
	return (int_color);
}
