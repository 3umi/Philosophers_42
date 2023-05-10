/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:25:29 by ohalim            #+#    #+#             */
/*   Updated: 2022/10/27 21:54:50 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 1;
	if (!lst)
		return (NULL);
	temp = lst;
	while (i < ft_lstsize(lst))
	{
		temp = temp->next;
		i++;
	}
	return (temp);
}
