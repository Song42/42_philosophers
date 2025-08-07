/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:40:33 by schaehun          #+#    #+#             */
/*   Updated: 2022/08/20 08:55:19 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*run(void *arg)
{
	struct s_philo	*philo;

	philo = (struct s_philo *) arg;
	if (philo->id % 2)
		usleep(420);
	while (philo->status == ALIVE)
	{
		philo_think(philo);
		if (take_forks(philo))
			break ;
		philo_eat(philo);
		philo->time_last_eat = time_present(1000);
		usleep(philo->info->time_eat * 1000);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		if (philo_death(philo))
			break ;
		philo_sleep(philo);
		if (philo->status == FULL)
			break ;
		usleep(philo->info->time_sleep * 1000);
	}
	return (NULL);
}
