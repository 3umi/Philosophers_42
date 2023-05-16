/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:34:22 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/16 03:14:11 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo_bonus.h"

void	wait_for_processes(pid_t *pid, int nb_of_proc)
{
	int	i;
	int	exit_status;

	i = 0;
	while (waitpid(-1, &exit_status, 0) != -1)
	{
		printf("in the while() wait in wait_for_processes\n");
		if (WEXITSTATUS(exit_status) == 1)
		{
			while (i < nb_of_proc)
			{
				printf("in the while() kill in wait_for_processes\n");
				kill(pid[i], SIGKILL);
				i++;
			}
			printf("Killed processes and ready to exit the main onen\n");
			exit (0);
		}
	}
	printf("Out of while() in wait_for_processes\n");
	exit (0);
}

int	check_death(t_philo philo)
{
	if ((timestamp() - philo.last_meal) >= philo.data->t_to_die)
	{
		printf("%d waiting for display in check_death\n", philo.rank);
		sem_wait(philo.data->display);
		printf("%d waited for display in check_death\n", philo.rank);
		printf("%lu ms %d %s\n", current_timestamp(philo.data->creation_time),
			philo.rank, DIE);
		return (FAILURE_RETURN);
	}
	return (SUCCESS_RETURN);
}

void	*circle(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->rank % 2 == 0)
		ft_usleep(philo->data->t_to_eat);
	while (1)
	{
		__eat(philo);
		ft_borintafo(philo, SLEEP);
		ft_usleep(philo->data->t_to_sleep);
		ft_borintafo(philo, THINK);
	}
}

void	init_circle(t_philo *philo)
{
	pthread_t	id;

	philo->last_meal = timestamp();
	philo->last_meal_s = sem_open("last_meal_s", O_CREAT, 0666, 1);
	if (philo->last_meal_s == SEM_FAILED)
			return ;
	if (pthread_create(&id, NULL, &circle, philo) != 0)
		return ;
	ft_usleep(WAIT);
	while (1)
	{
		if (check_death(*philo))
			exit(1);
	}
}
