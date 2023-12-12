/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-c <cde-la-c@student.42adel.org.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:33:31 by cde-la-c          #+#    #+#             */
/*   Updated: 2023/12/10 16:36:14 by cde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philosophers.h"

/**
 * @brief ft_error takes in a string and prints it to the standard error,
 * then frees the philos struct and exits the program.
 *
 * @param msg
 * @param philos
 * @return void
 */
void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}
