/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:36:27 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/08 14:18:43 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void	ft_usleep(unsigned long time_in_milli)
{
	usleep(time_in_milli * 1000);
}

void	ft_borintafo(s_philo *philo, char *def)
{
	pthread_mutex_lock(philo->input->display);
	printf("%lu ms %d %s\n", current_timestamp(philo->creation_time), philo->rank, def);
	pthread_mutex_unlock(philo->input->display);
}

void    __eat(s_philo *philo)
{
	pthread_mutex_lock(&philo->fork[philo->rank - 1]);
	ft_borintafo(philo, FORK);
	pthread_mutex_lock(&philo->fork[philo->rank]);
	ft_borintafo(philo, FORK);
	ft_borintafo(philo, EAT);
	ft_usleep(philo->input->t_to_eat);
	philo->last_meal = timestamp();
	pthread_mutex_unlock(&philo->fork[philo->rank - 1]);
	pthread_mutex_unlock(&philo->fork[philo->rank]);
}

void	__sleep(s_philo *philo)
{
	ft_borintafo(philo, SLEEP);
	usleep(philo->input->t_to_sleep * 1000);
}

