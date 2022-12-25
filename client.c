/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chobyounghwa <chobyounghwa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:53:39 by chobyounghw       #+#    #+#             */
/*   Updated: 2022/12/26 01:22:07 by chobyounghw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	formatWord(char word, int serverPID)
{
	unsigned char	num;
	int				idx;

	idx = 0;
	num = 0x80;
	while (idx < 8)
	{
		sendSignal(word & num, serverPID);
		num >>= 1;
		idx++;
	}
	return ;
}

void	sendSignal(int bit, int serverPID)
{
	if (bit)
		kill(serverPID, SIGUSR2);
	else
		kill(serverPID, SIGUSR1);
	usleep(100);
	return ;
}

int main(int argc, char* argv[])
{
    int server_pid;
    int len;
    int i;

    if (argc != 3)
    {
        ft_putstr_fd("Usage : ./client server process id string\n", 1);
        return (0);
    }
    server_pid = ft_atoi(argv[1]);

    if (!(server_pid > 100 && server_pid < 100000))
	{
		ft_putstr_fd("Invalid serverPID\n", 1);
		return (0);
	}
	i = 0;
	len = ft_strlen(argv[2]);
	while (i < len)
	{
		formatWord(argv[2][i], server_pid);
		i++;
	}
	formatWord('\n', server_pid);
	return (0);
}