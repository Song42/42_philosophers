/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:46:46 by schaehun          #+#    #+#             */
/*   Updated: 2022/08/19 07:26:59 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	struct s_info	info;
	struct s_philo	*philo;
	pthread_t		*philo_th;

	if (check_args(argc, argv))
		return (1);
	if (init_info(&info, argv))
		return (2);
	philo = malloc(sizeof(struct s_philo) * info.total_num);
	if (!philo)
	{
		de_init_forks(&info, info.total_num);
		return (3);
	}
	if (init_philo(philo, &info))
		return (4);
	philo_th = malloc(sizeof(pthread_t) * info.total_num);
	if (!philo_th)
	{
		de_init_philo(philo, &info);
		return (5);
	}
	if (init_thread(philo, &info, philo_th))
		return (6);
	de_init_all(philo, &info, philo_th);
}
