/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:02:11 by bcho              #+#    #+#             */
/*   Updated: 2023/04/22 15:02:15 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run(t_philo *philo, t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->philo_num)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, &(philo[i])))
			return (1);
	}
	if (monitor_philo(philo, info))
		return (1);
	i = -1;
	while (++i < info->philo_num)
		pthread_join(philo[i].thread, NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (error_message("invalid arguments\n"));
	if (!memset(&info, 0, sizeof(t_info)))
		return (error_message("fail memset\n"));
	if (init(argc, argv, &info, &philo))
		return (1);
	if (run(philo, &info) == 1)
		return (error_of_philo(philo, &info, "fail pthread_create\n"));
	ft_free(philo, &info);
	return (0);
}
