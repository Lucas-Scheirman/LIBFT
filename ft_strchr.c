/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:20:09 by lscheirm          #+#    #+#             */
/*   Updated: 2026/03/21 19:13:02 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t				i;
	unsigned char		char1;
	const unsigned char	*str1;

	char1 = (unsigned char)c;
	str1 = (const unsigned char *)s;
	i = 0;
	while (str1[i])
	{
		if (str1[i] == char1)
			return ((char *)&str1[i]);
		i++;
	}
	if (str1[i] == char1)
		return ((char *)&str1[i]);
	return (NULL);
}

/* Cherche la premiere occurrence de c dans la string s.
** Retourne un pointeur sur le caractere trouve, NULL sinon. */
