/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:10:57 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/13 23:23:31 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo_bonus.h"

int	parse_args(int argc)
{
	if (argc > 6 || argc < 5)
		return (__print_error("Usage:\n\t./philo\t  [nbr_of_philos]\t[t_to_die]\
        [t_to_eat]\t [t_to_sleep]\t [nb_of_circles](optional)\n"));
	return (SUCCESS_RETURN);
}

int	check_input(char **argv)
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
		philo->circle_x = __calloc(sizeof(pthread_mutex_t), 1);
		philo->circle = __atoi(argv[5]);
	}
	else
		philo->data->nb_of_circle = -1;
}
