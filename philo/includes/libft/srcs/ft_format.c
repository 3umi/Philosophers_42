/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:50:56 by ohalim            #+#    #+#             */
/*   Updated: 2022/11/07 23:04:41 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_format(const char *str_format, va_list args)
{
	int	len;

	len = 0;
	if (*str_format == '%')
		len += ft_putchar('%');
	if (*str_format == 'c')
		len += ft_putchar(va_arg(args, int));
	if (*str_format == 's')
		len += ft_putstr(va_arg(args, char *));
	if (*str_format == 'd' || *str_format == 'i')
		len += ft_putnbr(va_arg(args, int));
	if (*str_format == 'u')
		len += ft_putnbr_u(va_arg(args, unsigned int));
	if (*str_format == 'X' || *str_format == 'x')
		len += ft_putnbr_hexa(va_arg(args, unsigned int), *str_format == 'X');
	if (*str_format == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putnbr_hexa(va_arg(args, unsigned long), 0);
	}
	return (len);
}
