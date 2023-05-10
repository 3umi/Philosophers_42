/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:42:06 by ohalim            #+#    #+#             */
/*   Updated: 2022/10/27 21:57:59 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*nxt;

	temp = *lst;
	if (!lst || !del)
		return ;
	while (temp)
	{
		nxt = temp->next;
		ft_lstdelone(temp, del);
		temp = nxt;
	}
	*lst = NULL;
}
