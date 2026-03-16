/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 09:47:33 by lscheirm          #+#    #+#             */
/*   Updated: 2026/03/16 09:53:35 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_tab(size_t word, char c, char **multiple_str, char const *s)
{
	size_t	i;
	size_t	y;
	size_t	k;

	i = 0;
	k = 0;
	y = 0;
	while (i < word)
	{
		while (s[y] && s[y] == c)
			y++;
		while (s[y] && s[y] != c)
		{
			multiple_str[i][k] = s[y];
			k++;
			y++;
		}
		multiple_str[i][k] = 0;
		k = 0;
		i++;
	}
}

static void	free_tab(size_t i, char **multiple_str)
{
	while (i--)
		free(multiple_str[i]);
}

static int	create_tab(char const *s, char c, char **multiple_str, size_t word)
{
	size_t	i;
	size_t	y;
	size_t	k;

	i = 0;
	y = 0;
	while (i < word)
	{
		k = 0;
		while (s[y] && s[y] == c)
			y++;
		while (s[y] && s[y] != c)
		{
			k++;
			y++;
		}
		multiple_str[i] = malloc(k + 1);
		if (!multiple_str[i])
		{
			free_tab(i, multiple_str);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	count_word(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	if (s[i] && s[i] != c)
		word++;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			if (s[i] && s[i] != c)
				word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	word;
	char	**multiple_str;

	if (!s)
		return (NULL);
	word = count_word(s, c);
	multiple_str = malloc((word + 1) * sizeof(char *));
	if (!multiple_str)
		return (NULL);
	multiple_str[word] = NULL;
	if (create_tab(s, c, multiple_str, word) == 0)
	{
		free(multiple_str);
		return (NULL);
	}
	init_tab(word, c, multiple_str, s);
	return (multiple_str);
}
