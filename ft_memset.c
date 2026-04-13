/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 07:33:06 by lscheirm          #+#    #+#             */
/*   Updated: 2026/04/13 17:07:33 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	char1;
	unsigned char	*str1;

	char1 = (unsigned char)c;
	str1 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str1[i] = char1;
		i++;
	}
	return (s);
}
