<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/3umi/philosophers_42?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/3umi/philosophers_42?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/3umi/philosophers_42?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/3umi/philosophers_42?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/3umi/philosophers_42?color=green" />
</p>

# **Philosophers**

## *Description*

<div align="center">
	<b> This program is a simulation of the dining philosophers problem. <br> <br> </b>
	<img src="Resources/GIF/philo.gif" style="height: 275px; width:450px;background-color: #17202A;">
</div>

## *Overview*
	./philo [nb_of_philos] [t_to_die] [t_to_eat] [t_to_sleep] [number_of_times_each_philosopher_must_eat]
<p>
	<ul>
		<i>
			<li><b>nb_of_philos</b> :  The number of philosophers and also the number of <b>forks</b>.</li><br>
			<li><b>t_to_die</b> (in milliseconds): If a philosopher didn’t start eating <b>t_to_die</b> milliseconds since the beginning of their last meal or the beginning of the simulation, they die.</li> <br>
			<li><b>t_to_eat</b> (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold <b>two forks</b>.</li> <br>
			<li><b>t_to_sleep</b> (in milliseconds):  The time a philosopher will spend sleeping.</li><br>
			<li><b>number_of_times_each_philosopher_must_eat</b> (optional argument):  If all philosophers have eaten at least <b>number_of_times_each_philosopher_must_eat</b> times, the simulation stops. If not specified, the simulation stops when a philosopher dies.</li>
		</i>
	</ul>
</p>
