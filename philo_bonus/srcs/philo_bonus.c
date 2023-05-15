/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:04:05 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/15 05:00:00 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo_bonus.h"

void	wait_for_processes(pid_t *pid, int nb_of_proc)
{
	int	i;
	int	check;
	int	exit_status;


	check = 0;
	while (check < nb_of_proc)
	{
		waitpid(-1, &exit_status, 0);
		if (WEXITSTATUS(exit_status) == 1)
				break ;
		if (WEXITSTATUS(exit_status) == 2)
			check++;
	}
	i = -1;
	while (++i < nb_of_proc)
		kill(pid[i], SIGKILL);
}


int	main(int argc, char **argv)
{
	pid_t	*pid;

	sem_unlink("circle_s");
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