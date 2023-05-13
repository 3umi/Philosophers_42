/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:34:51 by ohalim            #+#    #+#             */
/*   Updated: 2023/02/09 21:38:37 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_hex(char *str)
{
	int		var[4];
	char	*u_hex;
	char	*l_hex;

	u_hex = ft_strdup("0123456789ABCDEF");
	l_hex = ft_strdup("0123456789abcdef");
	var[0] = 0;
	var[1] = ft_strlen(str) - 1;
	var[2] = 0;
	var[3] = 0;
	while (var[1] >= 0)
	{
		while (u_hex[var[0]] != str[var[1]] && l_hex[var[0]] != str[var[1]])
			var[0]++;
		var[2] += var[0] * pow(16, var[3]);
		var[3]++;
		var[1]--;
		var[0] = 0;
	}
	free (u_hex);
	free (l_hex);
	return (var[2]);
}
