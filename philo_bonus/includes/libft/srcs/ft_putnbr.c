/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:58:52 by ohalim            #+#    #+#             */
/*   Updated: 2022/11/08 01:00:07 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr(int n)
{
	size_t		len;
	long int	nbr;

	len = 0;
	nbr = n;
	if (nbr == -2147483648)
		len += ft_putstr("-2147483648");
	else if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
	{
		len += ft_putnbr(nbr / 10);
		len += ft_putchar(nbr % 10 + 48);
	}
	if (nbr >= 0 && nbr <= 9)
		len += ft_putchar(nbr + '0');
	return (len);
}
