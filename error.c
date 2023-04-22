/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:01:57 by bcho              #+#    #+#             */
/*   Updated: 2023/04/22 15:36:49 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_message(char *message)
{
	printf("%s\n", message);
	return (1);
}

int	error_of_mutex(t_info *info, char *message, int errno)
{
	while (*message)
		write(2, message++, 1);
	if (errno == 1)
		pthread_mutex_destroy(&(info->mutex_print));
	else if (errno == 2)
	{
		pthread_mutex_destroy(&(info->mutex_print));
		pthread_mutex_destroy(&(info->mutex_dead));
	}
	else if (errno == 3)
	{
		pthread_mutex_destroy(&(info->mutex_print));
		pthread_mutex_destroy(&(info->mutex_dead));
		pthread_mutex_destroy(&(info->mutex_all_eaten));
	}
	else if (errno == 4)
		free_mutex_fork(info);
	return (1);
}

int	error_of_philo(t_philo *philo, t_info *info, char *message)
{
	printf("%s\n", message);
	ft_free(philo, info);
	return (1);
}

void	free_mutex_fork(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(info->mutex_print));
	pthread_mutex_destroy(&(info->mutex_dead));
	pthread_mutex_destroy(&(info->mutex_all_eaten));
	while (i < info->philo_num && &(info->fork[i++]))
		pthread_mutex_destroy(&(info->fork[i++]));
	free(info->fork);
}

int	is_nbr(char *nbr)
{
	while ((9 <= *nbr && *nbr <= 13) || *nbr == ' ')
		nbr++;
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	if (*nbr == '\0')
		return (0);
	while (*nbr)
	{
		if (*nbr < '0' || '9' < *nbr)
			return (0);
		if (*nbr == '\"')
			return (0);
		nbr++;
	}
	return (1);
}
