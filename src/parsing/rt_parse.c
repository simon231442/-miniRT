/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                          :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: simon2314 <simon2314@42lausanne.ch>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:38:18 by simon2314         #+#    #+#             */
/*   Updated: 2025/11/21 14:58:49 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		parse_line(char	*line, t_la_complete *la_complete);
static t_parser *parser_tab_get(void);
static int		parser_find(char *line, t_parser parser_tab[], t_la_complete *la_complete);
static int		identifier_cmp(char *line, char *indentifier);

int	rt_parse(char *path, t_la_complete *la_complete)
{
	char	*line;
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ERROR_SYSTEM);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (parse_line(line, la_complete))
			return (1);
	}
	return (0);
}

static int	parse_line(char	*line, t_la_complete *la_complete)
{
	static t_parser	*parser_tab;

	parser_tab = parser_tab_get();
	while (1)
	{
//		rt_parse_line_count_is_valid();
		parser_find(line, parser_tab, la_complete);
	}
	return (0);
}

static t_parser	*parser_tab_get(void)
{
	static	t_parser	parser_tab[] = {
	{"A", rt_parse_ambient},
	{"C", rt_parse_cam},
	{"L", rt_parse_light},
	{"sp", rt_parse_sphere},
	{"pl", rt_parse_plane},
	{"cy", rt_parse_cylinder},
	{NULL, NULL}
	};

	return (parser_tab);
}

static int	parser_find(char *line, t_parser parser_tab[], t_la_complete *la_complete)
{
	int	i;

	i = 0;
	while (parser_tab[i].identifier)
	{
		if (identifier_cmp(line, parser_tab[i].identifier))
			return (parser_tab[i].f(line, la_complete));
	}
	return (1);
}

static int	identifier_cmp(char *line, char *identifier)
{
	int	i;

	i = 0;
	while (line[i] == identifier[i] && identifier[i])
		i++;
	if (!identifier[i])
		return (1);
	else
		return (0);
}
