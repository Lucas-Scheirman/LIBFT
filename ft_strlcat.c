/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:52:38 by lscheirm          #+#    #+#             */
/*   Updated: 2026/04/13 20:54:04 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	len_src;
	size_t	i;
	size_t	y;
	size_t	len_dst;

	len_dst = 0;
	while (len_dst < dsize && dst[len_dst])
		len_dst++;
	len_src = ft_strlen(src);
	i = 0;
	y = len_dst;
	if (dsize <= len_dst)
		return (dsize + len_src);
	while (src[i] && i < dsize - len_dst - 1)
	{
		dst[y] = src[i];
		i++;
		y++;
	}
	dst[y] = '\0';
	return (len_dst + len_src);
}
