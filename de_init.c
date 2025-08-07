/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   de_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 09:43:09 by schaehun          #+#    #+#             */
/*   Updated: 2022/08/19 07:27:02 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	de_init_forks(struct s_info *info, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		pthread_mutex_destroy(&info->forks[i]);
	free(info->forks);
}

void	de_init_philo(struct s_philo *philo, struct s_info *info)
{
	free(philo);
	de_init_forks(info, info->total_num);
}

void	de_init_all(struct s_philo *philo, struct s_info *info,
	pthread_t *philo_th)
{
	free(philo);
	free(philo_th);
	de_init_forks(info, info->total_num);
}
