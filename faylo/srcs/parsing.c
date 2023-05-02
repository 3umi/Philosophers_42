/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:29:29 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/02 16:56:41 by ohalim           ###   ########.fr       */
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

int	parse_input(int argc, char **argv, s_philo *philo)
{
	if (parse_args(argc) || check_input(argv))
		return (FAILURE_RETURN);
	philo = (s_philo *)__calloc(sizeof(s_philo), 1);
	if (!philo)
		return (FAILURE_RETURN);
	philo->input = (s_input *)__calloc(sizeof(s_input), 1);
	if (!philo->input)
		return (FAILURE_RETURN);
	philo->input->nbr_of_philos = __atoi(argv[1]);
	philo->input->t_to_die = __atoi(argv[2]);
	philo->input->t_to_eat = __atoi(argv[3]);
	philo->input->t_to_sleep = __atoi(argv[4]);
	if (argc == 6)
		philo->input->nb_of_circles = __atoi(argv[5]);
	return (SUCCESS_RETURN);
}
