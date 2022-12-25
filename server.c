/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chobyounghwa <chobyounghwa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 01:15:54 by chobyounghw       #+#    #+#             */
/*   Updated: 2022/12/26 00:07:24 by chobyounghw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(void)
{
    pid_t   serverPID;    //프로세스 번호를 저장하는 타입. unistd.h 헤더
    
    serverPID = getpid();   //get
    if (serverPID != 0)
    {
        ft_putstr_fd("serverPId : ", STDOUT);
        ft_putnbr_fd(serverPID, STDOUT);
        ft_putstr_fd("\n", STDOUT);
    }
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while(1)
        pause();
    return (0);
    
}

void handler(int sig)
{
    static char receive = 0;
    static int sendedBit = 0;

    receive = receive<<1;  //1비트 이동.
    if (sig == SIGUSR1)
    {
        receive += 1;
    }
    sendedBit++;
    if (sendedBit == 8)
    {
        ft_putchar_fd(receive, 1);
        receive = 0;
        sendedBit = 0;
    }
    return ;
}