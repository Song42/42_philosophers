/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:39:34 by schaehun          #+#    #+#             */
/*   Updated: 2022/08/20 08:58:12 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_the_end(struct s_philo *philo)
{
	int	i;
	int	n;
	int	total;

	i = -1;
	n = philo[0].info->total_num;
	total = 0;
	while (++i < n)
		if (philo[i].count_eat >= philo[i].info->must_eat)
			++total;
	if (total == n)
	{
		i = -1;
		while (++i < n)
			philo[i].status = FULL;
		return (1);
	}
	return (0);
}

int	monitoring(struct s_philo *philo)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (i < philo->info->total_num)
	{
		if (time_present(1000) - philo[i].time_last_eat
			>= (size_t) philo[i].info->time_life + 2)
			while (++j < philo->info->total_num)
				philo[j].status = DEAD;
		if (philo[i].status == DEAD)
		{
			printf("%ld %d died\n", timestamp(philo) - 2, philo[i].id);
			return (1);
		}
		if (philo->info->must_eat != -1)
			if (is_the_end(philo))
				return (0);
		if (++i == philo->info->total_num)
			i = 0;
		usleep(100);
	}
	return (0);
}
