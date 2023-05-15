/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:59:54 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/15 03:20:02 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <signal.h>

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

typedef struct s_data
{
	int				nb_of_philo;
	int				nb_of_circle;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	long			creation_time;
	sem_t			*fork;
	sem_t			*display;
}	t_data;

typedef struct s_philo
{
	int				rank;
	int				circle;
	long			last_meal;
	sem_t			*last_meal_s;
	sem_t			*circle_s;
	t_data			*data;
}	t_philo;

//---------------------Parsing_utils-------------------//
void	*__calloc(size_t count, size_t size);
size_t	__strlen(char *str);
int		__check_argv(char *str);
int		__atoi(char *str);
int		__print_error(char *str);

//----------------------Parsing------------------------//
int		check_argc(int argc);
int		check_argv(char **argv);
pid_t	*init_processes(int argc, char **argv);

//----------------------Init_utils------------------------//
void	ft_usleep(long time);
long	timestamp(void);
long	current_timestamp(long start_time);
void	ft_borintafo(t_philo *philo, char *def);
void	__eat(t_philo *philo);

//-------------------------Init------------------------//
int		check_death(t_philo philo);
int		check_circle(t_philo *philo);
void	*stalk_thread(void *arg);
void	init_circle(t_philo philo);

#endif