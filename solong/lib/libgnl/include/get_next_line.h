/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:20:53 by bcho              #+#    #+#             */
/*   Updated: 2023/01/21 13:55:16 by bcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1024

char	*ft_strchr2(char *s, int c);
int		ft_strlen2(char *str);
char	*ft_strjoin2(char *s1, char *s2);
char	*making_backup(int fd, char *backup);
char	*making_newbackup(char *backup);
char	*making_ans(char *backup);
char	*get_next_line(int fd);

#endif