/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 09:39:34 by schaehun          #+#    #+#             */
/*   Updated: 2022/08/19 10:30:11 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_long_atoi(const char *nptr)
{
	int			i;
	long long	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (nptr[i] == '+' && sign == 1)
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		num = num * 10 + (nptr[i++] - '0');
		if (num > 2147483647 && sign == 1)
			return (-1);
		if (num > 2147483648 && sign == -1)
			return (-1);
	}
	return (num * sign);
}

int	check_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (1);
	if (ft_long_atoi(argv[1]) > 200 || ft_long_atoi(argv[1]) < 1)
		return (1);
	if (ft_long_atoi(argv[2]) < 0 || ft_long_atoi(argv[3]) < 100
		|| ft_long_atoi(argv[4]) < 100)
		return (1);
	if (argv[5])
		if (ft_long_atoi(argv[5]) < 1)
			return (1);
	return (0);
}
