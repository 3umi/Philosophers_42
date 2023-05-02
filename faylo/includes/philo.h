/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:14:43 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/02 16:55:20 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../includes/libft/includes/libft.h"

# include <stdio.h>
# include <pthread.h>
# include <string.h>


# ifndef MAX
#  define MAX 2147483647
# endif

# ifndef MIN
#  define MIN -2147483648
# endif

# ifndef SUCCESS_RETURN
#  define SUCCESS_RETURN 0
# endif

# ifndef FAILURE_RETURN
#  define FAILURE_RETURN 1
# endif

# ifndef UNDEFINED_RETURN
#  define UNDEFINED_RETURN 2
# endif

typedef struct	t_input
{
	int 	nbr_of_philos;
	int 	t_to_die;
	int 	t_to_eat;
	int 	t_to_sleep;
	int 	nb_of_circles;
}   s_input;

typedef struct	t_philo
{
	s_input			*input;
	int				rank;
	struct t_philo	*right;
	struct t_philo	*left;
}	s_philo;

//---------------------Parsing_utils-------------------//
void	*__calloc(size_t count, size_t size);
size_t	__strlen(char *str);
int		__check_argv(char *str);
int		__atoi(char *str);
int		__print_error(char *str);

//----------------------Parsing------------------------//
int	parse_input(int argc, char **argv, s_philo *philo);

//----------------------Init_utils------------------------//


//-------------------------Init---------------------------//
void	init_threads(s_philo *philo);

#endif