/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:27:13 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/09 18:55:02 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

int main(int argc, char **argv)
{
	t_philo	*philo;

	philo = parse_input(argc, argv);
	if (!philo)
		return (FAILURE_RETURN);
	if (init_threads(philo))
		return (FAILURE_RETURN);
	if (stalk_threads(philo))
		return (FAILURE_RETURN);
	return (SUCCESS_RETURN);
}
