/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon2314 <simon2314@42lausanne.ch>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 19:38:18 by simon2314         #+#    #+#             */
/*   Updated: 2025/11/20 19:38:18 by simon2314        ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_parse(char *path, t_la_complete la_complet)
{
	char	*line;
	int	fd;

	while (line)
	{
		line = get_next_line(int 	
