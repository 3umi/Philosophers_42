/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:32:30 by ohalim            #+#    #+#             */
/*   Updated: 2022/10/27 22:29:29 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

static char	*ft_strrev(char	*s)
{
	int		i;
	int		count;
	char	temp;

	i = 0;
	count = 0;
	while (s[count])
		count++;
	count--;
	while (i < count)
	{
		temp = s[i];
		s[i] = s[count];
		s[count] = temp;
		i++;
		count--;
	}
	return (s);
}

static size_t	ft_allocation(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	if (n > 0)
	{
		while (n)
		{
			count++;
			n = n / 10;
		}
	}
	return (count + 1);
}

static void	write_minus(char *s, int n, int *i)
{
	if (n < 0)
	{
		s[*i] = '-';
		*i += 1;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		z;
	char	*s;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
		s = (char *)malloc(ft_allocation(n) * sizeof(char));
	if (!s)
		return (NULL);
	z = n;
	if (n < 0)
		n *= -1;
	while (n)
	{
		s[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	write_minus(s, z, &i);
	s[i] = '\0';
	return (ft_strrev(s));
}
