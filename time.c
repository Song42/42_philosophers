/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:38:44 by schaehun          #+#    #+#             */
/*   Updated: 2022/08/15 12:38:48 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	time_present(int scale)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (scale == 1000)
		return (time.tv_sec * 1000 + time.tv_usec / 1000);
	if (scale == 100000)
		return (time.tv_sec * 1000000 + time.tv_usec);
	return (0);
}

size_t	timestamp(struct s_philo *philo)
{
	size_t	timestamp;

	timestamp = time_present(1000) - philo->info->time_start;
	return (timestamp);
}
