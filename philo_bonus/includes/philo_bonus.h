/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:59:54 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/13 16:11:57 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>

# include "libft/includes/libft.h"

# define MAX 2147483647
# define MIN -2147483648
# define SUCCESS_RETURN 0
# define FAILURE_RETURN 1
# define UNDEFINED_RETURN 2

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "died"

#endif