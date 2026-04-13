/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 17:55:08 by lscheirm          #+#    #+#             */
/*   Updated: 2026/04/13 16:35:08 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*str1;
	const unsigned char	*str2;

	if (n == 0)
		return (dest);
	str1 = (unsigned char *)dest;
	str2 = (const unsigned char *)src;
	if (str1 < str2)
	{
		i = 0;
		while (i < n)
		{
			str1[i] = str2[i];
			i++;
		}
	}
	else
	{
		while (n--)
			str1[n] = str2[n];
	}
	return (dest);
}
