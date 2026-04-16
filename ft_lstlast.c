/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:05:38 by lscheirm          #+#    #+#             */
/*   Updated: 2026/04/14 18:06:09 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	t_list *lst;
	t_list *lst2;

	lst = ft_lstnew("HELLO");
	lst2 = ft_lstnew("HELLA");
	lst -> next = lst2;

	printf("%s",(char *)ft_lstlast (lst) -> content);
}*/
