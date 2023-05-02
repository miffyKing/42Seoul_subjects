# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chobyounghwa <chobyounghwa@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 19:10:29 by chobyounghw       #+#    #+#              #
#    Updated: 2022/12/15 20:35:57 by chobyounghw      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 				= CC

CFLAGS			= -Wall -Wextra -Werror

HEADER			= ft_printf.h

SRCS			= ft_printf.c \
				ft_utils.c\
				print_func.c

OBJS			= $(SRCS:c=o)

NAME			=libftprintf.a

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)
	
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	
re:
		make fclean
		make all
	
.PHONY: all clean fclean re