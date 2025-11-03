/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:20:35 by srenaud           #+#    #+#             */
/*   Updated: 2024/10/24 10:25:26 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trim;
	int long	sub_start;
	int long	sub_len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	if (set[0] == '\0')
		return (ft_strdup(s1));
	sub_start = 0;
	while (ft_isset(s1[sub_start], set))
		sub_start++;
		sub_len = 0;
	while (s1[sub_start + sub_len])
		sub_len++;
	sub_len--;
	while (ft_isset((s1[sub_start + sub_len]), set))
		sub_len--;
	sub_len++;
	if (sub_len < 1)
		return (ft_strdup(""));
	trim = ft_substr(s1, (unsigned int)sub_start, (size_t)sub_len);
	return (trim);
}
