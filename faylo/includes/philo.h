/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:14:43 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/09 21:47:48 by ohalim           ###   ########.fr       */
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
#  define WAIT 15
#  define FORK "has taken a fork"
#  define EAT "is eating"
#  define SLEEP "is sleeping"
#  define THINK "is thinking"
#  define DIE "died"

typedef struct	s_data
{
	int 			nb_of_philo;
	int 			nb_of_circle;
	int 			t_to_die;
	int 			t_to_eat;
	int 			t_to_sleep;
	long			creation_time;
	pthread_mutex_t	*display;
}   t_data;

typedef struct	s_philo
{
	int				rank;
	long			last_meal;
	pthread_t		id;
	pthread_mutex_t	*last_meal_x;
	pthread_mutex_t	*fork;
	t_data			*data;
}	t_philo;

//---------------------Parsing_utils-------------------//
void	*__calloc(size_t count, size_t size);
size_t	__strlen(char *str);
int		__check_argv(char *str);
int		__atoi(char *str);
int		__print_error(char *str);

//----------------------Parsing------------------------//
t_philo	*parse_input(int argc, char **argv);

//----------------------Init_utils------------------------//
void	ft_borintafo(t_philo *philo, char *def);
void    __eat(t_philo *philo);
void	__sleep(t_philo *philo);

//-------------------------Init---------------------------//
int		init_threads(t_philo *philo);
long	timestamp(void);
long	current_timestamp(long start_time);

//----------------------Main_thread_utils------------------------//
int		stalk_threads(t_philo *philo);

#endif