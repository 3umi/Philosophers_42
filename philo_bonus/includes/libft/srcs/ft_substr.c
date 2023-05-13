/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 07:29:52 by ohalim            #+#    #+#             */
/*   Updated: 2022/10/27 22:11:34 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*s_sub;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup("\0"));
	else if (len > ft_strlen(s))
		s_sub = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		s_sub = (char *) malloc(sizeof(char) * (len + 1));
	if (!s_sub)
		return (NULL);
	while (s[start] && i < len)
		s_sub[i++] = s[start++];
	s_sub[i] = '\0';
	return (s_sub);
}
