/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:35:58 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/05 14:48:37 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

unsigned long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec) * 1000) + tv.tv_usec / 1000);
}

unsigned long	get_current_time(unsigned long start_time)
{
	return (timestamp() - start_time);
}

void	*circle(void *arg)
{
	s_philo *philo;

	philo = arg;
	printf("rank: %d, %ld ms\n", philo->rank, get_current_time(philo->time));
	return (NULL);
}

int	init_threads(s_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->input->nbr_of_philos)
	{
		philo[i].rank = i;
		philo[i].time = timestamp();
		if (pthread_create(&philo[i].id, NULL, &circle, philo + i) != 0)
			return (__print_error("Not enough resources to create threads.\n"));
		i++;
	}
	return (SUCCESS_RETURN);
}
