/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-c <cde-la-c@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:26:17 by cde-la-c          #+#    #+#             */
/*   Updated: 2023/12/10 13:38:44 by cde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philosophers.h"
#include "../incl/utils.h"

void	parse_args(int argc, char **argv, t_program *program)
{
	program->nb_philo = ft_atoi(argv[1]);
	if (program->nb_philo < 0)
		ft_error("Wrong argument: nb of philos\n");
	program->ttd = ft_atoi(argv[2]);
	if (program->ttd < 0)
		ft_error("Wrong argument: time to die\n");
	program->tte = ft_atoi(argv[3]);
	if (program->tte < 0)
		ft_error("Wrong argument: time to eat\n");
	program->tts = ft_atoi(argv[4]);
	if (program->tts < 0)
		ft_error("Wrong argument: time to sleep\n");
	program->nb_eats = -1;
	if (argc == 6)
		program->nb_eats = ft_atoi(argv[5]);
	if (argc == 6 && program->nb_eats < 0)
		ft_error("Wrong argument: nb of times each philo. must eat\n");
	program->all_ate = 0;
	program->dead_flag = 0;
}
