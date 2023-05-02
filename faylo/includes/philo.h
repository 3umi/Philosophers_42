/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:14:43 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/02 01:47:11 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../includes/libft/includes/libft.h"

# include <stdio.h>
# include <pthread.h>
# include <string.h>


# define SUCESS_RETURN 0
# define FAILURE_RETURN 1

typedef struct	t_arg
{
	int		argc;
	char	**argv;
}	s_arg;

typedef struct	t_input
{
	s_arg	*arg;
	int 	nbr_of_philos;
	int 	t_to_die;
	int 	t_to_eat;
	int 	t_to_sleep;
	int 	death_circle;
}   s_input;

typedef struct	t_philo
{
	s_input	*input;
}	s_philo;

int parse_args(s_philo *philo, int argc, char **argv);

#endif