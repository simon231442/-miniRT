/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <unistd.h>

#include "libft.h"

#include "rt_error.h"

static void	rt_putendl_stderr(const char *message)
{
	if (!message)
		return ;
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
}

static void	rt_error_output(const char *message)
{
	write(2, "Error\n", 6);
	if (message != NULL)
		rt_putendl_stderr(message);
}

int	rt_error(const char *message)
{
	rt_error_output(message);
	return (1);
}

int	rt_error_errno(const char *message)
{
	const char	*detail;

	detail = strerror(errno);
	if (message != NULL)
	{
		rt_error_output(message);
		rt_putendl_stderr(detail);
	}
	else
		rt_error_output(detail);
	return (1);
}
