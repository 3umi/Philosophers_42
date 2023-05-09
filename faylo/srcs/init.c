/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:35:58 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/09 19:13:13 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec) * 1000) + (tv.tv_usec / 1000));
}

long	current_timestamp(long start_time)
{
	return (timestamp() - start_time);
}

void	*circle(void *arg)
{
	t_philo *philo;

	philo = arg;
	if ((philo->rank % 2) == 0)
		ft_usleep(philo->data->t_to_eat);
	while (1)
	{
		__eat(philo);
		__sleep(philo);
		ft_borintafo(philo, THINK);
	}
	return (NULL);
}

int	init_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_of_philo)
	{
		philo[i].data->creation_time = timestamp();
		philo[i].rank = i + 1;
		philo[i].last_meal = timestamp();
		pthread_mutex_init(&philo->fork[i], NULL);
		pthread_mutex_init(philo[i].data->display, NULL);
		if (pthread_create(&philo[i].id, NULL, &circle, philo + i) != 0)
			return (__print_error("Not enough resources to create threads.\n"));
		i++;
	}
	return (SUCCESS_RETURN);
}

