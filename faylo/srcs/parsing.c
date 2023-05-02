/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:29:29 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/02 03:23:59 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

static int parse_args(int argc)
{
	if (argc > 6 || argc < 5)
	{
		__print_error("Usage:\n\t./philo nbr_of_philos t_to_die t_to_eat t_to_sleep\
		[nb_of_circles](optional)\n");
		return (1);
	}
	return (0);
}

static int	check_input(char **argv)
{
	int	index;

	index = 1;
	while (argv[index])
	{
		if (__check_argv(argv[index]))
		{
			__print_error("Usage:\n\tNumeric input is required.\n");
			return (1);
		}
		index++;
	}
	return (0);
}

int	parse_input(int argc, char **argv, s_philo *philo)
{
	if (parse_args(argc) || check_input(argv))
		return (1);
	philo = (s_philo *)ft_calloc(sizeof(s_philo), 1);
	if (!philo)
		return (1);
	philo->input = (s_input *)ft_calloc(sizeof(s_input), 1);
	if (!philo->input)
		return (1);
	philo->input->nbr_of_philos = __atoi(argv[1]);
	philo->input->t_to_die = __atoi(argv[2]);
	philo->input->t_to_eat = __atoi(argv[3]);
	philo->input->t_to_sleep = __atoi(argv[4]);
	if (argc == 6)
		philo->input->nb_of_circles = __atoi(argv[5]);
	return (0);
}
