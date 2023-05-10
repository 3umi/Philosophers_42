/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:55:39 by ohalim            #+#    #+#             */
/*   Updated: 2022/10/20 13:45:55 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_size;
	int		src_size;

	i = 0;
	dest_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && (i + dest_size < dstsize - 1))
	{
		dst[i + dest_size] = src[i];
		i++;
	}
	dst[i + dest_size] = '\0';
	if (dest_size < dstsize)
		return (dest_size + src_size);
	return (src_size + dstsize);
}
