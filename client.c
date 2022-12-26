/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:53:39 by chobyounghw       #+#    #+#             */
/*   Updated: 2022/12/26 20:27:12 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	format_word(char word, int serverpid)
{
	unsigned char	num;
	int				idx;

	idx = 0;
	num = 0x80;
	while (idx < 8)
	{
		send_signal(word & num, serverpid);
		num >>= 1;
		idx++;
	}
	return ;
}

void	send_signal(int bit, int serverpid)
{
	if (bit)
		kill(serverpid, SIGUSR2);
	else
		kill(serverpid, SIGUSR1);
	usleep(300);
	return ;
}

int	main(int argc, char *argv[])
{
	int	server_pid;
	int	len;
	int	i;

	if (argc != 3)
	{
		ft_putstr_fd("format is -> ./client [server PID] [string to send]\n", 1);
		return (0);
	}
	server_pid = ft_atoi(argv[1]);
	if (!(server_pid > 100 && server_pid < 100000))
	{
		ft_putstr_fd("Invalid server process ID\n", 1);
		return (0);
	}
	i = 0;
	len = ft_strlen(argv[2]);
	argv[2] = ft_strjoin(argv[2], "\n");
	while (i < len + 1)
	{
		format_word(argv[2][i], server_pid);
		usleep(100);
		i++;
	}
	return (0);
}
