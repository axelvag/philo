/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:43:22 by avaganay          #+#    #+#             */
/*   Updated: 2023/05/30 14:01:54 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	main(int argc, char **argv)
{
	t_all	all;

	if (!(ft_pars_arg(argc, argv, &all)))
		return (ft_exit("Invalid Arguments\n"));
	gettimeofday(all.time_start, NULL);
	all.philo = malloc(sizeof(t_philo) * all.arg_all.number_of_philosopher);
	if (!all.philo)
		return (ft_exit("Malloc\n"));
	return (0);
}