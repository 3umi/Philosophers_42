/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:23:57 by ohalim            #+#    #+#             */
/*   Updated: 2022/10/24 08:10:49 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*tempo;

	new = NULL;
	tempo = NULL;
	tmp = lst;
	if (!lst || !f || !del)
		return (NULL);
	while (tmp)
	{
		tempo = ft_lstnew(f(tmp->content));
		if (!tempo)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tempo);
		tmp = tmp->next;
	}
	return (new);
}
