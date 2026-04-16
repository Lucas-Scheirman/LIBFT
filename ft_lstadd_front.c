/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:01:18 by lscheirm          #+#    #+#             */
/*   Updated: 2026/04/14 16:42:21 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int main ()
{
	t_list *new;
	t_list *lst;

	new = ft_lstnew("dxfdf");
	lst = ft_lstnew("Arbitre");


	printf("%s\n",(char *)lst -> content);
	ft_lstadd_front(&lst, new);
	printf("%s\n",(char *)lst -> content);
	ft_lstadd_front(NULL, NULL);
}*/
