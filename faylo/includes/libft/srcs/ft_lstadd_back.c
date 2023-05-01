/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:45:39 by ohalim            #+#    #+#             */
/*   Updated: 2022/10/28 11:59:04 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *nw)
{
	t_list	*p;

	if (!lst || !nw)
		return ;
	if (*lst == NULL)
	{
		*lst = nw;
		return ;
	}
	p = ft_lstlast (*lst);
	p->next = nw;
}
