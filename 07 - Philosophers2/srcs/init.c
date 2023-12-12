/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-c <cde-la-c@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:19:18 by cde-la-c          #+#    #+#             */
/*   Updated: 2023/12/10 13:39:19 by cde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philosophers.h"

int	init_mutex(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->nb_philo)
	{
		if (pthread_mutex_init(&(prog->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(prog->write_lock), NULL))
		return (1);
	if (pthread_mutex_init(&(prog->meal_lock), NULL))
		return (1);
	return (0);
}

int	init_philosophers(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->nb_philo)
	{
		prog->philosophers[i].id = i;
		prog->philosophers[i].meals_eaten = 0;
		prog->philosophers[i].right_fork = i;
		prog->philosophers[i].left_fork = (i + 1) % prog->nb_philo;
		prog->philosophers[i].last_meal = 0;
		prog->philosophers[i].prog = prog;
		prog->philosophers[i].dead = 0;
		i++;
	}
	return (0);
}

int	init_all(t_program *prog)
{
	if (init_mutex(prog))
		ft_error("Error initiating mutexes");
	init_philosophers(prog);
	return (0);
}
