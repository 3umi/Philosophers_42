/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:23:36 by ohalim            #+#    #+#             */
/*   Updated: 2022/10/20 14:06:44 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		n;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		n = 0;
		while (haystack[i + n] == needle[n] && haystack[i + n])
			n++;
		if (needle[n] == '\0')
		{
			if (i + ft_strlen(needle) > len)
				return (NULL);
			return ((char *) haystack + i);
		}
		i++;
	}
	return (NULL);
}
