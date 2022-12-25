/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chobyounghwa <chobyounghwa@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:53:51 by chobyounghw       #+#    #+#             */
/*   Updated: 2022/12/26 01:28:40 by chobyounghw      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINITALK_H
#   define MINITALK_H

# define STDOUT 1

#   include <signal.h>
#   include <stdlib.h>
#   include <unistd.h>

void	ft_putstr_fd(char *s, int fd);
static void	ft_print_nbr(int n, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char	*str);
char	*ft_strjoin(char const *s1, char const *s2);

int	ft_atoi(const char *str);


void handler(int sig);
void	formatWord(char word, int serverPID);
void	sendSignal(int bit, int serverPID);




#endif