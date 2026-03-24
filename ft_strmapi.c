/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:39:20 by lscheirm          #+#    #+#             */
/*   Updated: 2026/03/11 09:39:20 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len_s;
	char	*new_string;

	if (!s)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	new_string = malloc(len_s + 1);
	if (!new_string)
		return (NULL);
	while (i < len_s)
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = 0;
	return (new_string);
}

/* Applique f a chaque caractere de s avec son index,
	retourne la nouvelle string. */
