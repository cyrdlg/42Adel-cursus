/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.C                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-c <cde-la-c@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:25:20 by cde-la-c          #+#    #+#             */
/*   Updated: 2023/12/10 18:25:02 by cde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philosophers.h"

void	eat(t_program *prog, t_philosopher *philo)
{
	pthread_mutex_lock(&(prog->forks[philo->left_fork]));
	messaging(prog, philo->id, "has taken a fork");
	if (philo->prog->nb_philo == 1)
	{
		ft_usleep(philo->prog->ttd, prog);
		pthread_mutex_unlock(&(prog->forks[philo->left_fork]));
		return ;
	}
	pthread_mutex_lock(&(prog->forks[philo->right_fork]));
	messaging(prog, philo->id, "has taken a fork");
	pthread_mutex_lock(&(prog->meal_lock));
	philo->last_meal = ft_get_time();
	messaging(prog, philo->id, "is eating");
	pthread_mutex_unlock(&(prog->meal_lock));
	ft_usleep(prog->tte, prog);
	(philo->meals_eaten)++;
	pthread_mutex_unlock(&(prog->forks[philo->left_fork]));
	pthread_mutex_unlock(&(prog->forks[philo->right_fork]));
}

void	*thread_routine(void *void_philosopher)
{
	int				i;
	t_philosopher	*philo;
	t_program		*prog;

	i = 0;
	philo = (t_philosopher *)void_philosopher;
	prog = philo->prog;
	if (philo->id % 2)
		ft_usleep(10, prog);
	while (!(prog->dead_flag))
	{
		eat(prog, philo);
		if (prog->all_ate)
			break ;
		messaging(prog, philo->id, "is sleeping");
		ft_usleep(prog->tts, prog);
		messaging(prog, philo->id, "is thinking");
		i++;
	}
	return (NULL);
}
