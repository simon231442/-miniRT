/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_parser_utils_numeric.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

#include "rt_math.h"
#include "rt_scene_parser_utils.h"

static int	rt_scene_atod(const char *str, double *value)
{
	size_t	index;
	double	sign;
	double	result;
	double	delta;

	if (str == NULL || value == NULL)
		return (1);
	index = 0;
	while (str[index] == ' ' || str[index] == '\t')
		index++;
	sign = 1.0;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = -1.0;
		index++;
	}
	if (ft_isdigit((unsigned char)str[index]) == 0 && str[index] != '.')
		return (1);
	result = 0.0;
	while (ft_isdigit((unsigned char)str[index]) != 0)
	{
		result = (result * 10.0) + (double)(str[index] - '0');
		index++;
	}
	delta = 0.1;
	if (str[index] == '.')
	{
		index++;
		if (ft_isdigit((unsigned char)str[index]) == 0)
			return (1);
		while (ft_isdigit((unsigned char)str[index]) != 0)
		{
			result += (double)(str[index] - '0') * delta;
			delta *= 0.1;
			index++;
		}
	}
	while (str[index] == ' ' || str[index] == '\t')
		index++;
	if (str[index] != '\0')
		return (1);
	*value = result * sign;
	return (0);
}

int	rt_scene_parse_double(const char *str, double min, double max, double *out)
{
	double	value;

	if (rt_scene_atod(str, &value) != 0)
		return (1);
	if (value < min || value > max)
		return (1);
	*out = value;
	return (0);
}

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

int	rt_scene_parse_vec3(const char *str, t_vec3 *out)
{
	char	**items;
	double	x;
	double	y;
	double	z;

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
	if (rt_scene_atod(items[0], &x) != 0)
	{
		rt_scene_free_array(items);
		return (1);
	}
	if (rt_scene_atod(items[1], &y) != 0)
	{
		rt_scene_free_array(items);
		return (1);
	}
	if (rt_scene_atod(items[2], &z) != 0)
	{
		rt_scene_free_array(items);
		return (1);
	}
	rt_scene_free_array(items);
	*out = rt_math_vec3(x, y, z);
	return (0);
}

int	rt_scene_parse_vec3_normalized(const char *str, t_vec3 *out)
{
	double	length;

	if (rt_scene_parse_vec3(str, out) != 0)
		return (1);
	if (out->x < -1.0 || out->x > 1.0)
		return (1);
	if (out->y < -1.0 || out->y > 1.0)
		return (1);
	if (out->z < -1.0 || out->z > 1.0)
		return (1);
	length = rt_math_vec3_length(*out);
	if (length < RT_EPSILON)
		return (1);
	*out = rt_math_vec3_normalize(*out);
	return (0);
}
