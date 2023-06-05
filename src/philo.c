/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:43:22 by avaganay          #+#    #+#             */
/*   Updated: 2023/06/05 09:26:13 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	ft_thread(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->arg_all.number_of_philosopher)
	{
		all->philo[i].arg = &all->arg_all;
		if (pthread_create(&all->philo[i].thread_id, NULL, ft_routine,
				&all->philo[i]) != 0)
			return (ft_exit("Error: pthread_create\n"));
		pthread_join(all->philo[i].thread_id, NULL);
		if (all->philo[i].finish == 1)
			return (1);
		usleep(50);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (!(ft_pars_arg(argc, argv, &all)))
		return (ft_exit("Invalid Arguments\n"));
	gettimeofday(&all.arg_all.time_start, NULL);
	all.philo = malloc(sizeof(t_philo) * all.arg_all.number_of_philosopher);
	if (!all.philo)
		return (ft_exit("Malloc\n"));
	all.end = 0;
	all.nb_philo_finish = 0;
	if (ft_init(&all) == 0 || ft_thread(&all))
		return (free(all.philo), 0);
	return (0);
}

// int	main(void)
// {
// 	t_all	all;

// 	gettimeofday(&all.time_start, NULL);
// 	printf("%d\n", ft_time_current(all.time_start));
// 	return (0);
// }
