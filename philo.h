/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:47:40 by schaehun          #+#    #+#             */
/*   Updated: 2022/08/19 07:27:15 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

enum e_status
{
	ALIVE,
	FULL,
	DEAD,
};

struct s_info
{
	int				total_num;
	size_t			time_start;
	int				time_life;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	pthread_mutex_t	*forks;
};

struct s_philo
{
	int				id;
	struct s_info	*info;
	int				status;
	size_t			time_last_eat;
	int				count_eat;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
};

size_t		time_present(int scale);
size_t		timestamp(struct s_philo *philo);

int			check_args(int argc, char **argv);
int			ft_atoi(const char *nptr);
long long	ft_long_atoi(const char *nptr);

int			init_info(struct s_info *info, char **argv);
int			init_philo(struct s_philo *philo, struct s_info *info);
int			init_thread(struct s_philo *philo, struct s_info *info,
				pthread_t *philo_th);

void		de_init_forks(struct s_info *info, int n);
void		de_init_philo(struct s_philo *philo, struct s_info *info);
void		de_init_all(struct s_philo *philo, struct s_info *info,
				pthread_t *philo_th);

int			monitoring(struct s_philo *philo);

void		philo_think(struct s_philo *philo);
void		philo_eat(struct s_philo *philo);
void		philo_sleep(struct s_philo *philo);
int			philo_death(struct s_philo *philo);

int			take_forks(struct s_philo *philo);

void		*run(void *arg);

#endif
