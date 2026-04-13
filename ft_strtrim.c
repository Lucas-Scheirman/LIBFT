/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 09:46:58 by lscheirm          #+#    #+#             */
/*   Updated: 2026/04/13 18:27:40 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_set(char c, char const *set)
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

static void	init_tab(size_t i, size_t y, char *str, char const *s1)
{
	size_t	j;

	j = 0;
	while (s1[i] && i <= y)
		str[j++] = s1[i++];
	str[j] = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	y;
	size_t	len_s1;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	len_s1 = ft_strlen(s1);
	if (len_s1 == 0)
		return (ft_strdup(""));
	y = len_s1 - 1;
	i = 0;
	while (find_set(s1[i], set))
		i++;
	if (s1[i] == 0)
		return (ft_strdup(""));
	while (find_set(s1[y], set))
		y--;
	str = malloc((((len_s1 - (len_s1 - y)) - i) + 2));
	if (!str)
		return (NULL);
	init_tab(i, y, str, s1);
	return (str);
}
