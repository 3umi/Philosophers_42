/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:22:06 by ohalim            #+#    #+#             */
/*   Updated: 2022/10/24 15:57:34 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*tab;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	tab = (unsigned char *) malloc(size * count);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < count * size)
		tab[i++] = 0;
	return (tab);
}
