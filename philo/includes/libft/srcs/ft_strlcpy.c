/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:50:54 by ohalim            #+#    #+#             */
/*   Updated: 2022/10/27 22:49:58 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (destsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < destsize - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (ft_strlen(src));
}
