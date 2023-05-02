/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 01:29:29 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/02 01:50:26 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void    print_error(char *str)
{
    if (!str)
        return;
    write(2, str, strlen(str));
}

int parse_args(s_philo *philo, int argc, char **argv)
{
    if (argc > 5 || argc < 4)
    {
        print_error("Usage:\n\t./philo nbr_of_philos t_to_die t_to_eat t_to_sleep\
        [death_circle](optional)\n");
        return (1);
    }
    (void)philo;
    (void)argv;
    return (0);
}