/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_parser_utils_color.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include "libft.h"

#include "rt_color.h"
#include "rt_scene_parser_utils.h"

static void	rt_scene_free_array(char **array)
{
	size_t	index;

	if (array == NULL)
		return ;
	index = 0;
	while (array[index] != NULL)
	{
		free(array[index]);
		index++;
	}
	free(array);
}

static int	rt_scene_is_integral(double value)
{
	double	rounded;

	rounded = floor(value + 0.5);
	if (fabs(value - rounded) < 0.000001)
		return (0);
	return (1);
}

int	rt_scene_parse_color(const char *str, t_color *out)
{
	char	**items;
	double	r;
	double	g;
	double	b;

	if (str == NULL || out == NULL)
		return (1);
	items = ft_split(str, ',');
	if (items == NULL)
		return (1);
	if (rt_scene_token_count(items) != 3)
	{
		rt_scene_free_array(items);
		return (1);
	}
	if (rt_scene_parse_double(items[0], 0.0, 255.0, &r) != 0)
	{
		rt_scene_free_array(items);
		return (1);
	}
	if (rt_scene_parse_double(items[1], 0.0, 255.0, &g) != 0)
	{
		rt_scene_free_array(items);
		return (1);
	}
	if (rt_scene_parse_double(items[2], 0.0, 255.0, &b) != 0)
	{
		rt_scene_free_array(items);
		return (1);
	}
	if (rt_scene_is_integral(r) != 0 || rt_scene_is_integral(g) != 0
		|| rt_scene_is_integral(b) != 0)
	{
		rt_scene_free_array(items);
		return (1);
	}
	rt_scene_free_array(items);
	*out = rt_color(r / 255.0, g / 255.0, b / 255.0);
	return (0);
}

int	rt_scene_is_empty_line(const char *line)
{
	if (line == NULL)
		return (1);
	if (line[0] == '\0')
		return (1);
	if (line[0] == '#')
		return (1);
	return (0);
}

size_t	rt_scene_token_count(char **tokens)
{
	size_t	count;

	if (tokens == NULL)
		return (0);
	count = 0;
	while (tokens[count] != NULL)
		count++;
	return (count);
}
