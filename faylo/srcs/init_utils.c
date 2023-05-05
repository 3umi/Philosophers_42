/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:36:27 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/05 20:27:07 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void    __eat(s_philo *philo)
{
    philo->last_meal = get_current_time(philo->last_meal);
    pthread_mutex_lock(philo->fork);
    pthread_mutex_lock((philo + 1)->fork);
    printf("%lu ms\t%d has taken a fork\t", philo->);
    usleep(philo->input->t_to_eat);
}
