/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohalim <ohalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:27:13 by ohalim            #+#    #+#             */
/*   Updated: 2023/05/01 15:27:31 by ohalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../includes/philo.h"

int				count = 0;
pthread_mutex_t	mutex;

void	*start_routine(void *arg)
{
	(void)arg;
	for (int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex);
		count++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int main()
{
	pthread_t	my_thread_uno;
	pthread_t	my_thread_dos;


	pthread_mutex_init(&mutex, NULL);

	pthread_create(&my_thread_uno, NULL, &start_routine, NULL);
	pthread_create(&my_thread_dos, NULL, &start_routine, NULL);
	
	pthread_join(my_thread_uno, NULL);
	pthread_join(my_thread_dos, NULL);

	printf("Count : %d\n", count);
	return (0);
}