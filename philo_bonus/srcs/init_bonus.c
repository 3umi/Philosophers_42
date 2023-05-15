/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:34:22 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/15 03:47:16 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo_bonus.h"

int	check_death(t_philo philo)
{
	sem_wait(philo.data->display);
	sem_wait(philo.last_meal_s);
	if ((timestamp() - philo.last_meal) >= philo.data->t_to_die)
	{
		printf("%lu ms %d %s\n", current_timestamp(philo.data->creation_time),
			philo.rank, DIE);
		return (FAILURE_RETURN);
	}
	sem_post(philo.data->display);
	sem_post(philo.last_meal_s);
	return (SUCCESS_RETURN);
}

void	*stalk_thread(void *arg)
{
	int	i;
	t_philo	*philo;

	philo = arg;
	i = 0;
	while (1)
	{
		if (check_death(*philo))
			exit(1);
	}
	exit (0);
}

void	init_circle(t_philo philo)
{
	pthread_t	id;

	philo.last_meal = timestamp();
	philo.circle_s = sem_open("circle_s", O_CREAT, 0666, 1);
	philo.last_meal_s = sem_open("last_meal_s", O_CREAT, 0666, 1);
	if (philo.circle_s == SEM_FAILED || philo.last_meal_s == SEM_FAILED)
			return ;
	if (pthread_create(&id, NULL, &stalk_thread, &philo) != 0)
			return ;
	while (1)
	{
		__eat(&philo);
		ft_borintafo(&philo, SLEEP);
		ft_usleep(philo.data->t_to_sleep);
		ft_borintafo(&philo, THINK);
	}
}
