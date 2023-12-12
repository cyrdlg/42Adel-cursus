/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-c <cde-la-c@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:20:40 by cde-la-c          #+#    #+#             */
/*   Updated: 2023/12/10 18:13:17 by cde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# define PHILO_MAX 200

typedef struct s_philosopher
{
	int					id;
	int					dead;
	int					meals_eaten;
	int					left_fork;
	int					right_fork;
	long long			last_meal;
	struct s_program	*prog;
	pthread_t			thread_id;
}	t_philosopher;

typedef struct s_program
{
	int					nb_philo;
	long long			ttd;
	long long			tte;
	long long			tts;
	int					nb_eats;
	int					dead_flag;
	int					all_ate;
	long long			start;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		forks[PHILO_MAX];
	t_philosopher		philosophers[PHILO_MAX];
}	t_program;

void		*thread_routine(void *void_philosopher);
void		messaging(t_program *prog, int id, char *string);
long long	ft_get_time(void);
long long	ft_get_time_diff(long long past, long long pres);
void		ft_usleep(long long time, t_program *prog);
int			ft_strlen(char *str);
void		ft_error(char *msg);
void		parse_args(int argc, char **argv, t_program *program);
int			init_all(t_program *prog);
int			run(t_program *prog);

#endif