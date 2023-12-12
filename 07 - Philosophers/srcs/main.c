/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-c <cde-la-c@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:53:43 by cde-la-c          #+#    #+#             */
/*   Updated: 2023/12/10 16:02:15 by cde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philosophers.h"

static void	usage(void)
{
	printf("./philo <1> <2> <3> <4> [5]\n");
	printf(" <1> number_of_philosophers\n");
	printf(" <2> time_to_die (ms)\n");
	printf(" <3> time_to_eat (ms)\n");
	printf(" <4> time_to_sleep (ms)\n");
	printf(" [5] number_of_times_each_philosopher_must_eat (optional)\n");
}

int	main(int argc, char **argv)
{
	t_program		prog;

	if (argc < 5 || argc > 6)
	{
		usage();
		return (0);
	}
	parse_args(argc, argv, &prog);
	init_all(&prog);
	if (run(&prog))
		ft_error("Error creating the threads\n");
	return (0);
}
