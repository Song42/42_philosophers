/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:40:11 by schaehun          #+#    #+#             */
/*   Updated: 2022/08/20 08:57:35 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(struct s_philo *philo)
{
	printf("%ld %d is thinking\n", timestamp(philo), philo->id);
}

void	philo_eat(struct s_philo *philo)
{
	printf("%ld %d is eating\n", timestamp(philo), philo->id);
	philo->count_eat++;
}

void	philo_sleep(struct s_philo *philo)
{
	printf("%ld %d is sleeping\n", timestamp(philo), philo->id);
}

int	philo_death(struct s_philo *philo)
{
	if (philo->status == DEAD)
		return (1);
	return (0);
}

int	take_forks(struct s_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	if (philo_death(philo) || philo->status == FULL)
	{
		pthread_mutex_unlock(philo->fork_left);
		return (1);
	}
	printf("%ld %d has taken a fork\n", timestamp(philo), philo->id);
	if (!philo->fork_right)
	{
		pthread_mutex_unlock(philo->fork_left);
		return (1);
	}
	pthread_mutex_lock(philo->fork_right);
	if (philo_death(philo) || philo->status == FULL)
	{
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		return (1);
	}
	printf("%ld %d has taken a fork\n", timestamp(philo), philo->id);
	return (0);
}
