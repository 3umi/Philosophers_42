/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:27:13 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/02 01:39:09 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../includes/philo.h"

int main(int argc, char **argv)
{
	s_philo	philo;

	if (parse_args(&philo, argc, argv))
		return (EXIT_FAILURE);
}