/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:29:29 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/08 20:50:00 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

static int parse_args(int argc)
{
	if (argc > 6 || argc < 5)
		return (__print_error("Usage:\n\t./philo\t  [nbr_of_philos]\t[t_to_die]\
        [t_to_eat]\t [t_to_sleep]\t [nb_of_circles](optional)\n"));
	return (SUCCESS_RETURN);
}

static int	check_input(char **argv)
{
	int	index;

	index = 1;
	while (argv[index])
	{
		if (__check_argv(argv[index]))
			return (__print_error("Usage:\n\tNumeric input is required.\n"));
        else if (__atoi(argv[index]) <= 0)
            return (__print_error("Usage:\n\tStrict positive input is required.\n"));
		index++;
	}
	return (SUCCESS_RETURN);
}

t_philo	*parse_input(int argc, char **argv)
{
	t_philo	*philo;
	int	i;

	i = 0;
	if (parse_args(argc) || check_input(argv))
		return (NULL);
	philo = __calloc(sizeof(t_philo), __atoi(argv[1]));
	if (!philo)
		return (NULL);
	while (i < __atoi(argv[1]))
	{
		philo[i].data = __calloc(sizeof(t_data), 1);
		philo[i].fork = __calloc(sizeof(pthread_mutex_t), __atoi(argv[1]));
		if (!philo[i].data || !philo[i].fork)
			return (NULL);
		philo[i].data->nb_of_philo = __atoi(argv[1]);
		philo[i].data->t_to_die = __atoi(argv[2]);
		philo[i].data->t_to_eat = __atoi(argv[3]);
		philo[i].data->t_to_sleep = __atoi(argv[4]);
		if (argc == 6)
			philo[i].data->nb_of_circle = __atoi(argv[5]);
		i++;
	}
	return (philo);
}
