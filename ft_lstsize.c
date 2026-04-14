/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:03:03 by lscheirm          #+#    #+#             */
/*   Updated: 2026/04/14 17:00:33 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
int main()
{
	t_list *lst;
	t_list *lst2;

	lst = ft_lstnew("fdgdf");
	lst2 = ft_lstnew("fdgdff");

	lst -> next = lst2;

	printf("%d",ft_lstsize(lst));
}*/
