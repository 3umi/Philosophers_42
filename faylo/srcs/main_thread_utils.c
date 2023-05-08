/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:15:01 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/08 21:43:42 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

int	check_death(t_philo philo)
{
	if ((timestamp() - philo.last_meal) >= philo.data->t_to_die)
		return (1);
	return (0);
}

void	stalk_threads(t_philo *philo)
{
	int	i;

	i = 0;
	ft_usleep(WAIT);
	while (i < philo->data->nb_of_philo)
	{
		if (check_death(philo[i]))
		{
			ft_borintafo(philo[i], DIE);
			return ;
		}
		i++;
	}
}