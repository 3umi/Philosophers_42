/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:46:49 by ohalim            #+#    #+#             */
/*   Updated: 2023/01/26 18:57:14 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	array_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	if (count)
		return (count);
	return (1);
}

static void	increment(const char *s, int *arr0, int *arr1, char c)
{
	while (s[*arr0] && s[*arr0] != c)
	{
		*arr0 += 1;
		*arr1 += 1;
	}
}

static char	**ft_free_tab(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		arr[4];

	if (!s)
		return (NULL);
	arr[0] = 0;
	arr[3] = 0;
	ptr = ft_calloc(((array_count(s, c) + 1)), sizeof(char *));
	if (!ptr)
		return (NULL);
	while (s[arr[0]])
	{
		if (s[arr[0]] == c)
			arr[0]++;
		else
		{
			arr[2] = arr[0];
			arr[1] = 0;
			increment(s, &arr[0], &arr[1], c);
			ptr[arr[3]] = ft_substr(s, arr[2], arr[1]);
			if (!ptr[arr[3]++])
				return (ft_free_tab(ptr));
		}
	}
	return (ptr);
}
