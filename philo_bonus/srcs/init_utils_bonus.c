/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:34:20 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/16 03:17:57 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo_bonus.h"

void	ft_usleep(long time)
{
	long	i;
	long	j;

	i = timestamp();
	j = timestamp();
	while ((i - j) < time)
	{
		usleep(100);
		i = timestamp();
	}
}

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

void	ft_borintafo(t_philo *philo, char *def)
{
	sem_wait(philo->data->display);
	printf("%lu ms %d %s\n", current_timestamp(philo->data->creation_time),
		philo->rank, def);
	sem_post(philo->data->display);
}

void	__eat(t_philo *philo)
{
	sem_wait(philo->data->fork);
	ft_borintafo(philo, FORK);
	sem_wait(philo->data->fork);
	ft_borintafo(philo, FORK);
	ft_borintafo(philo, EAT);
	if (philo->data->nb_of_circle > 0)
		philo->circle--;
	if (philo->circle == 0)
	{
		sem_post(philo->data->fork);
		sem_post(philo->data->fork);
		exit (0);
	}
	sem_wait(philo->last_meal_s);
	philo->last_meal = timestamp();
	sem_post(philo->last_meal_s);
	ft_usleep(philo->data->t_to_eat);
	sem_post(philo->data->fork);
	sem_post(philo->data->fork);
}
