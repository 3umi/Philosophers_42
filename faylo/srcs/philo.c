/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:27:13 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/05 13:15:06 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

int main(int argc, char **argv)
{
	s_philo	*philo;

	if (parse_input(argc, argv, &philo))
		return (FAILURE_RETURN);
	if (init_threads(philo))
		return (FAILURE_RETURN);
	return (SUCCESS_RETURN);
}
