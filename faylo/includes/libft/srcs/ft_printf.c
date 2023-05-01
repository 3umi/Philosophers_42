/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:37:51 by ohalim            #+#    #+#             */
/*   Updated: 2022/11/07 23:05:10 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_printf(const char *str_format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str_format);
	while (*str_format)
	{
		if (*str_format == '%')
			len += ft_format(++str_format, args);
		else
			len += ft_putchar(*str_format);
		if (*str_format)
			str_format++;
	}
	va_end(args);
	return (len);
}
