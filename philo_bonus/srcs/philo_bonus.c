/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:04:05 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/14 00:06:59 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo_bonus.h"

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;
	t_philo	*philo;

	i = 0;
	if (parse_args(argc) || check_input(argv))
		return (NULL);
	while (i < __atoi(argv[1]))
	{
		pid = fork();
		if (pid < 0)
			__print_error("Failed to create new process.\n");
		if (pid == 0)
			parse_input();
	}
	return (SUCCESS_RETURN);
}