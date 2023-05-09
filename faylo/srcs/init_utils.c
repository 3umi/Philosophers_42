/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:36:27 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/09 19:13:25 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void	ft_usleep(long time_in_milli)
{
	usleep(time_in_milli * 1000);
}

void	ft_borintafo(t_philo *philo, char *def)
{
	pthread_mutex_lock(philo->data->display);
	printf("%lu ms %d %s\n", current_timestamp(philo->data->creation_time), philo->rank, def);
	pthread_mutex_unlock(philo->data->display);
}
void    __eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork[philo->rank - 1]);
	ft_borintafo(philo, FORK);
	pthread_mutex_lock(&philo->fork[philo->rank % philo->data->nb_of_philo]);
	ft_borintafo(philo, FORK);
	ft_borintafo(philo, EAT);
	philo->last_meal = timestamp();
	ft_usleep(philo->data->t_to_eat);
	pthread_mutex_unlock(&philo->fork[philo->rank - 1]);
	pthread_mutex_unlock(&philo->fork[philo->rank % philo->data->nb_of_philo]);
}

void	__sleep(t_philo *philo)
{
	ft_borintafo(philo, SLEEP);
	ft_usleep(philo->data->t_to_sleep);
}

