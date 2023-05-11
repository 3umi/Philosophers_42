/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:15:01 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/11 21:40:59 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_death(t_philo philo)
{
	pthread_mutex_lock(philo.data->display);
	pthread_mutex_lock(philo.last_meal_x);
	if ((timestamp() - philo.last_meal) >= philo.data->t_to_die)
	{
		printf("%lu ms %d %s\n", current_timestamp(philo.data->creation_time),
			philo.rank, DIE);
		return (FAILURE_RETURN);
	}
	pthread_mutex_unlock(philo.data->display);
	pthread_mutex_unlock(philo.last_meal_x);
	return (SUCCESS_RETURN);
}

int	check_circle(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_of_philo)
	{
		pthread_mutex_lock(philo[i].circle_x);
		if (philo[i].circle > 0)
		{
			pthread_mutex_unlock(philo[i].circle_x);
			return (SUCCESS_RETURN);
		}
		pthread_mutex_unlock(philo[i].circle_x);
		i++;
	}
	return (FAILURE_RETURN);
}

int	stalk_threads(t_philo *philo)
{
	int	i;

	i = 0;
	ft_usleep(WAIT);
	while (1)
	{
		while (i < philo->data->nb_of_philo)
		{
			if (check_death(philo[i]))
				return (FAILURE_RETURN);
			i++;
		}
		i = 0;
		if (philo->data->nb_of_circle > 0)
		{
			if (check_circle(philo))
				return (FAILURE_RETURN);
		}
	}
	return (SUCCESS_RETURN);
}
