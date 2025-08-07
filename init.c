/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:39:14 by schaehun          #+#    #+#             */
/*   Updated: 2022/08/19 10:13:09 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_danger_args(struct s_info *info, char **argv)
{
	info->time_eat = ft_atoi(argv[3]);
	if (info->time_eat > info->time_life)
		info->time_eat = info->time_life + 10;
	info->time_sleep = ft_atoi(argv[4]);
	if (info->time_sleep > info->time_life)
		info->time_sleep = info->time_life + 10;
	if (argv[5])
		info->must_eat = ft_atoi(argv[5]);
	else
		info->must_eat = -1;
}

int	init_info(struct s_info *info, char **argv)
{
	int	i;

	memset(info, 0, sizeof(struct s_info));
	info->total_num = ft_atoi(argv[1]);
	info->time_start = time_present(1000);
	info->time_life = ft_atoi(argv[2]);
	init_danger_args(info, argv);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->total_num);
	if (!info->forks)
		return (1);
	i = -1;
	while (++i < info->total_num)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
		{
			de_init_forks(info, i);
			return (1);
		}
	}
	return (0);
}

void	init_forks(struct s_philo *philo, struct s_info *info, int i)
{
	if (info->total_num == 1)
	{
		philo[i].fork_left = &info->forks[i];
		philo[i].fork_right = NULL;
		return ;
	}
	if (i % 2)
	{
		philo[i].fork_left = &info->forks[i];
		philo[i].fork_right = &info->forks[(i + 1) % info->total_num];
	}
	else
	{
		philo[i].fork_left = &info->forks[(i + 1) % info->total_num];
		philo[i].fork_right = &info->forks[i];
	}
}

int	init_philo(struct s_philo *philo, struct s_info *info)
{
	int	i;

	i = -1;
	while (++i < info->total_num)
	{
		memset(&philo[i], 0, sizeof(struct s_philo));
		philo[i].id = i;
		philo[i].info = info;
		philo[i].status = ALIVE;
		philo[i].time_last_eat = time_present(1000);
		philo[i].count_eat = 0;
		init_forks(philo, info, i);
	}
	return (0);
}

int	init_thread(struct s_philo *philo, struct s_info *info, pthread_t *philo_th)
{
	int	i;

	i = -1;
	while (++i < info->total_num)
	{
		if (pthread_create(&philo_th[i], NULL, &run, (void *) &philo[i]))
		{
			while (i > 0)
			{
				philo[i - 1].status = DEAD;
				pthread_detach(philo_th[--i]);
			}
			return (1);
		}
	}
	monitoring(philo);
	i = -1;
	while (++i < info->total_num)
		if (pthread_join(philo_th[i], NULL))
			return (1);
	return (0);
}
