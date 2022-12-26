/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 01:15:54 by chobyounghw       #+#    #+#             */
/*   Updated: 2022/12/26 17:41:03 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	pid_t	serverpid;

	serverpid = getpid();
	if (serverpid)
	{
		ft_putstr_fd("serverpid : ", STDOUT);
		ft_putnbr_fd(serverpid, STDOUT);
		ft_putstr_fd("\n", STDOUT);
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}

void	handler(int sig)
{
	static char	receive = 0;
	static int	sendedbit = 0;

	receive = receive << 1;
	if (sig == SIGUSR2)
	{
		receive += 1;
	}
	sendedbit++;
	if (sendedbit == 8)
	{
		ft_putchar_fd(receive, 1);
		receive = 0;
		sendedbit = 0;
	}
	return ;
}
