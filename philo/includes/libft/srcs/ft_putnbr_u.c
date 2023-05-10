/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:26:41 by ohalim            #+#    #+#             */
/*   Updated: 2022/11/08 01:03:50 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr_u(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n > 9)
	{
		len += ft_putnbr_u(n / 10);
		len += ft_putchar(n % 10 + 48);
	}
	if (n >= 0 && n <= 9)
		len += ft_putchar(n + '0');
	return (len);
}
