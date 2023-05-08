/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:14:43 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/08 14:10:40 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# include "../includes/libft/includes/libft.h"

#  define MAX 2147483647
#  define MIN -2147483648
#  define SUCCESS_RETURN 0
#  define FAILURE_RETURN 1
#  define UNDEFINED_RETURN 2
#  define FORK "has taken a fork"
#  define EAT "is eating"
#  define SLEEP "is sleeping"
#  define THINK "is thinking"
#  define DIE "died"

typedef struct	t_input
{
	int 			nbr_of_philos;
	int 			t_to_die;
	int 			t_to_eat;
	int 			t_to_sleep;
	int 			nb_of_circles;
	pthread_mutex_t	*display;
}   s_input;

typedef struct	t_philo
{
	int				rank;
	unsigned long	creation_time;
	unsigned long	last_meal;
	pthread_mutex_t	*fork;
	pthread_t		id;
	s_input			*input;
}	s_philo;

//---------------------Parsing_utils-------------------//
void	*__calloc(size_t count, size_t size);
size_t	__strlen(char *str);
int		__check_argv(char *str);
int		__atoi(char *str);
int		__print_error(char *str);

//----------------------Parsing------------------------//
int	parse_input(int argc, char **argv, s_philo **philo);

//----------------------Init_utils------------------------//
void	ft_usleep(unsigned long time_in_milli);
void	ft_borintafo(s_philo *philo, char *def);
void    __eat(s_philo *philo);
void	__sleep(s_philo *philo);

//-------------------------Init---------------------------//
int				init_threads(s_philo *philo);
unsigned long	timestamp(void);
unsigned long	current_timestamp(unsigned long start_time);

#endif