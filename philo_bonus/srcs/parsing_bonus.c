/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:10:57 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/15 03:41:42 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo_bonus.h"

int	check_argc(int argc)
{
	if (argc > 6 || argc < 5)
		return (__print_error("Usage:\n\t./philo\t  [nbr_of_philos]\t[t_to_die]\
        [t_to_eat]\t [t_to_sleep]\t [nb_of_circles](optional)\n"));
	return (SUCCESS_RETURN);
}

int	check_argv(char **argv)
{
	int	index;

	index = 1;
	while (argv[index])
	{
		if (__check_argv(argv[index]))
			return (__print_error("Usage:\n\tNumeric input is required.\n"));
		else if (__atoi(argv[index]) <= 0)
		{
			write(2, "Usage:\n\t", 8);
			return (__print_error("Strict positive input is required.\n"));
		}
		index++;
	}
	return (SUCCESS_RETURN);
}

void	insert_data(int argc, char **argv, t_philo *philo)
{
	philo->data->nb_of_philo = __atoi(argv[1]);
	philo->data->t_to_die = __atoi(argv[2]);
	philo->data->t_to_eat = __atoi(argv[3]);
	philo->data->t_to_sleep = __atoi(argv[4]);
	if (argc == 6)
	{
		philo->data->nb_of_circle = __atoi(argv[5]);
		philo->circle = __atoi(argv[5]);
	}
	else
	{
		philo->data->nb_of_circle = -1;
		philo->circle = -1;
	}
}

pid_t	*init_processes(int argc, char **argv)
{
	int		i;
	pid_t	*pid;
	t_philo	philo;

	i = 0;
	pid = __calloc(sizeof(pid_t), __atoi(argv[1]));
	if (!pid)
		return (NULL);
	philo.data = __calloc(sizeof(t_data), 1);
	if (!philo.data)
		return (NULL);
	philo.data->fork = sem_open("forks", O_CREAT, 0666, __atoi(argv[1]));
	philo.data->display = sem_open("display", O_CREAT, 0666, 1);
	if (philo.data->fork == SEM_FAILED || philo.data->display == SEM_FAILED)
        return (NULL);
	while (i < __atoi(argv[1]))
	{
		philo.rank = i + 1;
		insert_data(argc, argv, &philo);
		pid[i] = fork();
		philo.data->creation_time = timestamp();
		if (pid[i] < 0)
			return (NULL);
		if (pid[i] == 0)
			init_circle(philo);
		i++;
	}
	return (pid);
}
