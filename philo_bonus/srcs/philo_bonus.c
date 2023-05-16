/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:04:05 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/16 02:48:42 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo_bonus.h"


int	main(int argc, char **argv)
{
	pid_t	*pid;

	sem_unlink("last_meal_s");
	sem_unlink("forks");
	sem_unlink("display");
	if (check_argc(argc) || check_argv(argv))
		return (FAILURE_RETURN);
	pid = init_processes(argc, argv);
	if (!pid)
		return (FAILURE_RETURN);
	wait_for_processes(pid, __atoi(argv[1]));
	return (SUCCESS_RETURN);
}