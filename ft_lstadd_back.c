/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheirm <lscheirm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:11:03 by lscheirm          #+#    #+#             */
/*   Updated: 2026/04/14 18:12:03 by lscheirm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_;

	if(!lst || !new)
		return;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst_ = ft_lstlast(*lst);
	lst_->next = new;
}
int main()

{
	t_list *lst;
	t_list *lst2;

}
