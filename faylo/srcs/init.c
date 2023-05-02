/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:35:58 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/02 23:15:13 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void	*circle(void *arg)
{
	(void)arg;
	printf("Thread function\n");
	return (NULL);
}

int	init_threads(s_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->input->nbr_of_philos)
	{
		if (pthread_create(&philo[i].id, NULL, &circle, NULL) != 0)
			return (__print_error("Not enough resources to create threads.\n"));
		philo[i].rank = i;
		i++;
	}
	return (SUCCESS_RETURN);
}
