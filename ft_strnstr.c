/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:51:11 by lscheirm          #+#    #+#             */
/*   Updated: 2026/03/18 19:41:05 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			y = 0;
			while (i + y < len && big[i + y] && little[y] && big[i
				+ y] == little[y])
				y++;
			if (little[y] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

/* Cherche la premiere occurrence de little dans big dans la
**limite de len octets.
** Retourne un pointeur sur l'occurrence trouvee, NULL sinon. */
