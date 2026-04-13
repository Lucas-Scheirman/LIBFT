/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:39:20 by lscheirm          #+#    #+#             */
/*   Updated: 2026/03/11 09:39:20 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_len(long nb)
{
	size_t	i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static void	init_tab(long nb, size_t size, char *tab_with_my_number)
{
	while (nb != 0)
	{
		tab_with_my_number[size] = (nb % 10) + '0';
		nb = nb / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	size;
	char	*tab_with_my_number;
	long	nb;

	nb = n;
	i = 0;
	size = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	size = str_len(nb);
	tab_with_my_number = malloc(size + 1 + i);
	if (!tab_with_my_number)
		return (NULL);
	if (i)
		tab_with_my_number[0] = '-';
	init_tab(nb, size + i - 1, tab_with_my_number);
	tab_with_my_number[size + i] = '\0';
	return (tab_with_my_number);
}
