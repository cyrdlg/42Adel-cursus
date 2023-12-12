/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-c <cde-la-c@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:05:31 by cde-la-c          #+#    #+#             */
/*   Updated: 2023/12/10 18:13:01 by cde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philosophers.h"

/**
 * @brief The ft_get_time returns the current time in milliseconds.
 * 
 * @return uint64_t 
 */
long long	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (-1);
	return ((long long)tv.tv_sec * 1000 + (long long)tv.tv_usec / 1000);
}

/**
 * @brief ft_get_time_diff returns the time elapsed since a timestamp 
 * in milliseconds.
 * 
 * @param time
 * @return uint64_t 
 */
long long	ft_get_time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	ft_usleep(long long time, t_program *prog)
{
	long long i;

	i = ft_get_time();
	while (!(prog->dead_flag))
	{
		if (ft_get_time_diff(i, ft_get_time()) >= time)
			break ;
		usleep(50);
	}
}
