/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:58:40 by lscheirm          #+#    #+#             */
/*   Updated: 2026/04/13 16:22:19 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		char1;
	const unsigned char	*str1;

	char1 = (unsigned char)c;
	str1 = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str1[i] == char1)
			return ((void *)&str1[i]);
		i++;
	}
	return (NULL);
}
