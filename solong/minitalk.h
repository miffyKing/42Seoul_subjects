/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:53:51 by chobyounghw       #+#    #+#             */
/*   Updated: 2022/12/26 17:35:57 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINITALK_H
# define MINITALK_H

# define STDOUT 1

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void		ft_putstr_fd(char *s, int fd);
static void	ft_print_nbr(int n, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
size_t		ft_strlen(const char	*str);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_atoi(const char *str);
void		handler(int sig);
void		format_word(char word, int serverpid);
void		send_signal(int bit, int serverpid);

#endif
