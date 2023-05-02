# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chobyounghwa <chobyounghwa@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/25 00:53:10 by chobyounghw       #+#    #+#              #
#    Updated: 2022/12/26 01:26:53 by chobyounghw      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGC = -Wall -Wextra -Werror
CC = gcc
src = server_utils.c client_utils.c
obj=$(src:.c=.o)
server = server
client = client
NAME = $(server) $(client) 
sersrc = server.c
clisrc = client.c
sobj = $(sersrc:.c=.o)
cobj = $(clisrc:.c=.o)

all: $(NAME)
   
$(server):$(obj) $(sobj) minitalk.h
	$(CC) $(CFLAGS) $(sobj) $(obj) -o $(server)
$(client):$(obj) $(cobj) minitalk.h
	$(CC) $(CFLAGS) $(cobj) $(obj) -o $(client)
%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(obj) $(sobj) $(cobj)
fclean: clean
	rm -rf $(NAME)
re: fclean all