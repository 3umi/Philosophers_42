/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:59:54 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/13 23:23:26 by ohalim           ###   ########.fr       */
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

typedef struct s_data
{
	int				nb_of_philo;
	int				nb_of_circle;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	long			creation_time;
	pthread_mutex_t	*display;
}	t_data;

typedef struct s_philo
{
	int				rank;
	int				circle;
	long			last_meal;
	pthread_t		id;
	pthread_mutex_t	*last_meal_x;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*circle_x;
	t_data			*data;
}	t_philo;

//---------------------Parsing_utils-------------------//
void	*__calloc(size_t count, size_t size);
size_t	__strlen(char *str);
int		__check_argv(char *str);
int		__atoi(char *str);
int		__print_error(char *str);

//----------------------Parsing------------------------//
int		parse_args(int argc);
int		check_input(char **argv);

#endif