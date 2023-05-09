/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:15:01 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/09 02:46:11 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

int	check_death(t_philo philo)
{
	pthread_mutex_lock(&philo.data->display);
	if ((timestamp() - philo.last_meal) >= philo.data->t_to_die)
	{
		usleep(1000);
		printf("%lu ms %d %s\n", current_timestamp(philo.data->creation_time), philo.rank, DIE);
		return (1);
	}
	pthread_mutex_unlock(&philo.data->display);
	return (0);
}

void	stalk_threads(t_philo *philo)
{
	int	i;

	i = 0;
	ft_usleep(WAIT);
	while (1)
	{
		while (i < philo->data->nb_of_philo)
		{
			if (check_death(philo[i]))
				return ;
			i++;
		}
		i = 0;
	}
}