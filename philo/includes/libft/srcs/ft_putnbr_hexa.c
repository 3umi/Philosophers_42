/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:15:05 by ohalim            #+#    #+#             */
/*   Updated: 2022/11/08 01:02:24 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr_hexa(unsigned long n, int is_uppercase)
{
	size_t	len;
	char	c;

	len = 0;
	if (n < 16)
	{
		if (n < 10)
			c = n + '0';
		else
			c = n + ('a' - (32 * is_uppercase)) - 10;
		len += ft_putchar(c);
	}
	else
	{
		len += ft_putnbr_hexa(n / 16, is_uppercase);
		len += ft_putnbr_hexa(n % 16, is_uppercase);
	}
	return (len);
}
