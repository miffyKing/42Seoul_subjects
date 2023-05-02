# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 15:02:16 by bcho              #+#    #+#              #
#    Updated: 2023/04/22 15:08:47 by bcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror #:wq-fsanitize=thread
RM = rm -f

NAME 		=	philo

SRCS		=	main.c \
				philo.c \
				init.c \
				utils.c \
				error.c \
				property.c \
				
OBJS		= $(SRCS:%.c=%.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o			:	%.c
		$(CC) $(CFLAGS) -c $^ -I./ -o $@

clean		:
		$(RM) $(OBJS)
		
fclean		:	clean
		$(RM) $(NAME)
		
re			:
		$(MAKE) fclean
		$(MAKE) all

.PHONY		:	all clean fclean re bonus
