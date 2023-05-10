/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:56:35 by ohalim            #+#    #+#             */
/*   Updated: 2022/10/19 16:01:14 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (destination > source)
	{
		while (len)
		{
			destination[len - 1] = source[len - 1];
			len--;
		}
	}
	else
	{
		ft_memcpy(destination, source, len);
	}
	return ((void *) destination);
}
