/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_scene_loader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "get_next_line.h"

#include "rt_scene.h"
#include "rt_scene_parser.h"
#include "rt_scene_parser_utils.h"
#include "rt_error.h"

typedef struct s_scene_flags
{
	int	ambient;
	int	camera;
	int	light;
}t_scene_flags;

static void	rt_scene_free_tokens(char **tokens)
{
	size_t	index;

	if (tokens == NULL)
		return ;
	index = 0;
	while (tokens[index] != NULL)
	{
		free(tokens[index]);
		index++;
	}
	free(tokens);
}

static char	**rt_scene_tokenize(char *line)
{
	size_t	index;

	index = 0;
	while (line[index] != '\0')
	{
		if (line[index] == '\t')
			line[index] = ' ';
		index++;
	}
	return (ft_split(line, ' '));
}

static int	rt_scene_dispatch(t_scene *scene, char **tokens, t_scene_flags *flags)
{
	int	status;

	if (tokens[0] == NULL)
		return (0);
	if (ft_strncmp(tokens[0], "A", 2) == 0)
	{
		if (flags->ambient != 0)
			return (rt_error("Ambient already defined"));
		status = rt_scene_parse_ambient(scene, tokens);
		if (status == 0)
			flags->ambient = 1;
		return (status);
	}
	if (ft_strncmp(tokens[0], "C", 2) == 0)
	{
		if (flags->camera != 0)
			return (rt_error("Camera already defined"));
		status = rt_scene_parse_camera(scene, tokens);
		if (status == 0)
			flags->camera = 1;
		return (status);
	}
	if (ft_strncmp(tokens[0], "L", 2) == 0)
	{
		if (flags->light != 0)
			return (rt_error("Light already defined"));
		status = rt_scene_parse_light(scene, tokens);
		if (status == 0)
			flags->light = 1;
		return (status);
	}
	if (ft_strncmp(tokens[0], "sp", 3) == 0)
		return (rt_scene_parse_sphere(scene, tokens));
	if (ft_strncmp(tokens[0], "pl", 3) == 0)
		return (rt_scene_parse_plane(scene, tokens));
	if (ft_strncmp(tokens[0], "cy", 3) == 0)
		return (rt_scene_parse_cylinder(scene, tokens));
	return (rt_error("Unknown identifier"));
}

static int	rt_scene_process_line(t_scene *scene, char *line, t_scene_flags *flags)
{
	char	*trimmed;
	char	**tokens;
	int	status;

	trimmed = ft_strtrim(line, " \t\r\n");
	if (trimmed == NULL)
		return (rt_error("Allocation failure"));
	if (trimmed[0] == '\0')
	{
		free(trimmed);
		return (0);
	}
	if (rt_scene_is_empty_line(trimmed) != 0)
	{
		free(trimmed);
		return (0);
	}
	tokens = rt_scene_tokenize(trimmed);
	free(trimmed);
	if (tokens == NULL)
		return (rt_error("Allocation failure"));
	status = rt_scene_dispatch(scene, tokens, flags);
	rt_scene_free_tokens(tokens);
	return (status);
}

int	rt_scene_load(t_scene *scene, const char *path)
{
	int			fd;
	char		*line;
	int			status;
	t_scene_flags	flags;

	if (scene == NULL || path == NULL)
		return (rt_error("Invalid scene input"));
	ft_bzero(&flags, sizeof(t_scene_flags));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (rt_error_errno("Failed to open scene"));
	status = 0;
	line = get_next_line(fd);
	while (line != NULL && status == 0)
	{
		status = rt_scene_process_line(scene, line, &flags);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (close(fd) < 0 && status == 0)
		status = rt_error_errno("Failed to close scene");
	if (status == 0 && (flags.ambient == 0 || flags.camera == 0 || flags.light == 0))
		status = rt_error("Missing mandatory element");
	return (status);
}
