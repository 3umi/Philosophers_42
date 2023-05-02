# include <pthread.h>

//--------------------------------------Arguments-----------------------------------//
/*
	-- > number_of_philosophers				: The number of philosophers and also 
												the number of forks.

	-- > time_to_die (in milliseconds)		: The servival time of the philosopher
												before dying of starving.

	-- > time_to_eat (in milliseconds)		: The time needed by the philosopher to eat.

	-- > time_to_sleep (in milliseconds)	: The time needed by the philosopher to sleep.

	-- > number_of_times_each_philosopher_must_eat
			(optional argument):
	If all philosophers have eaten at least number_of_times_each_philosopher_must_eat
	times, the simulation stops. If not specified, the simulation stops when a
	philosopher dies.
*/