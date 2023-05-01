/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:27:45 by ohalim            #+#    #+#             */
/*   Updated: 2022/10/27 21:40:02 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char ))
{
	int		i;
	char	*tab;

	i = 0;
	if (!s || !f)
		return (NULL);
	tab = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		tab[i] = f(i, s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
