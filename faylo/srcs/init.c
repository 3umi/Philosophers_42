/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:35:58 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/08 14:21:09 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

unsigned long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec) * 1000) + (tv.tv_usec / 1000));
}

unsigned long	current_timestamp(unsigned long start_time)
{
	return (timestamp() - start_time);
}

void	*circle(void *arg)
{
	s_philo *philo;

	philo = arg;
	if ((philo->rank % 2) == 0)
		usleep (philo->input->t_to_eat);
	while (1)
	{
		__eat(philo);
		__sleep(philo);
		ft_borintafo(philo, THINK);
	}
	return (NULL);
}

int	init_threads(s_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_init(philo->input->display, NULL);
	while (i < philo->input->nbr_of_philos)
	{
		philo[i].rank = i + 1;
		philo[i].creation_time = timestamp();
		philo[i].last_meal = philo[i].creation_time;
		pthread_mutex_init(philo[i].fork, NULL);
		if (pthread_create(&philo[i].id, NULL, &circle, philo + i) != 0)
			return (__print_error("Not enough resources to create threads.\n"));
		i++;
	}
	return (SUCCESS_RETURN);
}
