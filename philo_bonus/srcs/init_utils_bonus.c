/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:34:20 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/16 02:39:35 by ohalim           ###   ########.fr       */
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
	printf("%d waiting for display in ft_borintafo\n", philo->rank);
	sem_wait(philo->data->display);
	printf("%d waited for display in ft_borintafo\n", philo->rank);
	printf("%lu ms %d %s\n", current_timestamp(philo->data->creation_time),
		philo->rank, def);
	printf("%d posting for display in ft_borintafo\n", philo->rank);
	sem_post(philo->data->display);
	printf("%d posted for display in ft_borintafo\n", philo->rank);
}

void	__eat(t_philo *philo)
{
	printf("%d waiting for fork in __eat()\n", philo->rank);
	sem_wait(philo->data->fork);
	printf("%d waited for fork in __eat()\n", philo->rank);
	ft_borintafo(philo, FORK);
	printf("%d waiting for fork in __eat()\n", philo->rank);
	sem_wait(philo->data->fork);
	printf("%d waited for fork in __eat()\n", philo->rank);
	ft_borintafo(philo, FORK);
	ft_borintafo(philo, EAT);
	if (philo->data->nb_of_circle > 0)
		philo->circle--;
	printf("%d's cirle is: %d\n", philo->rank, philo->circle);
	if (philo->circle == 0)
	{
		printf("%d posting for fork in __eat()\n", philo->rank);
		sem_post(philo->data->fork);
		printf("%d posted for fork in __eat()\n", philo->rank);
		printf("%d posting for fork in __eat()\n", philo->rank);
		sem_post(philo->data->fork);
		printf("%d posted for fork in __eat()\n", philo->rank);
		printf("end of %d process\n", philo->rank);
		exit (0);
	}
	printf("%d waiting for last_meal in __eat()\n", philo->rank);
	sem_wait(philo->last_meal_s);
	printf("%d waited for last_meal in __eat()\n", philo->rank);
	philo->last_meal = timestamp();
	printf("%d posting for last_meal in __eat()\n", philo->rank);
	sem_post(philo->last_meal_s);
	printf("%d posted for last_meal in __eat()\n", philo->rank);
	ft_usleep(philo->data->t_to_eat);
	printf("%d posting for fork in __eat()\n", philo->rank);
	sem_post(philo->data->fork);
	printf("%d posted for fork in __eat()\n", philo->rank);
	printf("%d posting for fork in __eat()\n", philo->rank);
	sem_post(philo->data->fork);
	printf("%d posted for fork in __eat()\n", philo->rank);
}
