/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:02:54 by ohalim            #+#    #+#             */
/*   Updated: 2022/11/08 01:05:38 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putstr(char *str)
{
	size_t	len;

	len = 0;
	if (!(str))
		return (ft_putstr("(null)"));
	while (*str)
		len += ft_putchar(*(str++));
	return (len);
}
