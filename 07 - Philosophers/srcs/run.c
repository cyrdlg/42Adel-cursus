/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-c <cde-la-c@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:59:27 by cde-la-c          #+#    #+#             */
/*   Updated: 2023/12/10 20:15:28 by cde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philosophers.h"

void	is_dead(t_philosopher philo, t_program *prog)
{
	pthread_mutex_lock(&(prog->meal_lock));
	if (ft_get_time_diff(philo.last_meal, ft_get_time()) > prog->ttd)
	{
		messaging(prog, philo.id, "died");
		philo.dead = 1;
		prog->dead_flag = 1;
	}
	pthread_mutex_unlock(&(prog->meal_lock));
}

void	death_check(t_program *prog, t_philosopher *philos)
{
	int				i;

	while (!(prog->all_ate))
	{
		i = 0;
		while (i < prog->nb_philo && !(prog->dead_flag))
		{
			is_dead(philos[i], prog);
			i++;
			//ft_usleep(1, prog);
		}
		if (prog->dead_flag)
			break ;
		i = 0;
		while (prog->nb_eats != -1 && i < prog->nb_philo
			&& philos[i].meals_eaten >= prog->nb_eats)
			i++;
		if (i == prog->nb_philo)
			prog->all_ate = 1;
	}
}

void	exit_threads(t_program *prog)
{
	int	i;

	i = -1;
	while (++i < prog->nb_philo)
	{
		pthread_join(prog->philosophers[i].thread_id, NULL);
	}
	i = -1;
	while (++i < prog->nb_philo)
		pthread_mutex_destroy(&(prog->forks[i]));
	pthread_mutex_destroy(&(prog->write_lock));
	pthread_mutex_destroy(&(prog->meal_lock));
}

int	run(t_program *prog)
{
	int				i;
	t_philosopher	*ph;

	i = 0;
	ph = prog->philosophers;
	prog->start = ft_get_time();
	while (i < prog->nb_philo)
	{
		ph[i].last_meal = prog->start;
		if (pthread_create(&(ph[i].thread_id), NULL, thread_routine, &(ph[i])))
			return (1);
		i++;
	}
	death_check(prog, prog->philosophers);
	exit_threads(prog);
	return (0);
}
