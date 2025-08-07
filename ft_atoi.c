/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:25:39 by schaehun          #+#    #+#             */
/*   Updated: 2022/08/18 10:16:03 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
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
		if (num * sign < -2147483648)
			return (0);
	}
	return (num * sign);
}
