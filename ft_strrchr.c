/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:57:56 by lscheirm          #+#    #+#             */
/*   Updated: 2026/03/18 17:18:34 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t				i;
	unsigned char		char1;
	const unsigned char	*str1;

	char1 = (unsigned char)c;
	str1 = (const unsigned char *)s;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (str1[i] == char1)
			return ((char *)&str1[i]);
		i--;
	}
	if (str1[i] == char1)
		return ((char *)&str1[i]);
	return (NULL);
}

/* Cherche la derniere occurrence de c dans la string s.
** Retourne un pointeur sur le caractere trouve, NULL sinon. */
