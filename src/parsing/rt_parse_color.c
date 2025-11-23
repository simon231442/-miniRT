/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_color.c                                    :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:59:25 by srenaud           #+#    #+#             */
/*   Updated: 2025/11/21 10:07:30 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_parse_color(char *arg, t_color *color)
{
	char	**color_tmp;

	color_tmp = ft_split(arg, ',');
	if (!color_tmp)
		return (rt_error_put(ERROR_SYSTEM), 1);
	color->r = rt_parse_atod(color_tmp[0]);
	color->g = rt_parse_atod(color_tmp[1]);
	color->b = rt_parse_atod(color_tmp[2]); 
	return (free(color_tmp), 0);
}
