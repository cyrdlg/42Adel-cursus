/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messaging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-c <cde-la-c@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:54:19 by cde-la-c          #+#    #+#             */
/*   Updated: 2023/12/10 20:03:58 by cde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philosophers.h"

void	messaging(t_program *prog, int id, char *string)
{
	pthread_mutex_lock(&(prog->write_lock));
	if (!(prog->dead_flag))
	{
		printf("%lli %i %s\n", ft_get_time() - prog->start, id + 1, string);
	}
	pthread_mutex_unlock(&(prog->write_lock));
	return ;
}
