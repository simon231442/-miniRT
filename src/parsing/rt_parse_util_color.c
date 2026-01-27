/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_util_color.c                               :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:59:25 by srenaud           #+#    #+#             */
/*   Updated: 2025/11/21 10:07:30 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	color_is_valid(char **color);

int	rt_parse_util_color(char *arg, t_color *color)
{
	char	**color_tmp;

	color_tmp = ft_split(arg, ',');
	if (!color_tmp)
		return (rt_error_put(ERROR_SYSTEM), 1);
	if (!color_is_valid(color_tmp))
		return (1);
	color->r = rt_parse_util_atod(color_tmp[0]);
	color->g = rt_parse_util_atod(color_tmp[1]);
	color->b = rt_parse_util_atod(color_tmp[2]); 
	return (free(color_tmp), 0);
}

static int	color_is_valid(char **color)
{
	if (ft_arg_count(color) != 3)
		return (rt_error_put(ERROR_VECTOR), 0);
	while (*color)
	{
		if (!ft_real_format_is_valid(*color))
			return (rt_error_put(ERROR_REAL_NB_FORMAT), 0);
		if (!ft_real_is_in_range(*color,"0", "255"))
			return (rt_error_put(ERROR_OUT_OF_RANGE), 0);
		color++;
	}
	return (1);
}
