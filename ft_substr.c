/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:39:19 by lscheirm          #+#    #+#             */
/*   Updated: 2026/03/11 09:39:19 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= (unsigned int)slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	i = 0;
	tab = malloc(len + 1);
	if (!tab)
		return (NULL);
	while (i < len && s[start])
	{
		tab[i] = s[start];
		start++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

/* Alloue et retourne une sous-chaine de s,
	depuis start sur len caracteres max. */
