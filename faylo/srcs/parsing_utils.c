/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 03:07:07 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/02 03:19:10 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

size_t	__strlen(char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count])
		count++;
	return (count);
}

void    __print_error(char *str)
{
	if (!str)
		return;
	write(2, str, __strlen(str));
}

int	__check_argv(char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	sign = 1;
	num = 0;
	if (!str[i])
		return (1);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + (str[i++] - 48);
		else
			return (1);
	}
	return ((num * sign) > MAX || (num * sign) < MIN);
}

int	__atoi(char *str)
{
	int				i;
	unsigned long	num;
	int				sign;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\n')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		num = num * 10 + (str[i++] - 48);
		if (num > 9223372036854775807 && sign == 1)
			return (-1);
		if (num > 9223372036854775807 && sign == -1)
			return (0);
	}
	return (num * sign);
}

