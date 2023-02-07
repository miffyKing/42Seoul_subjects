# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcho <bcho@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 15:53:05 by bcho              #+#    #+#              #
#    Updated: 2023/01/15 15:53:09 by bcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libgnl.a

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

INCLUDE	= -I./include

SRC_DIR	= ./src
SRC = \
	$(SRC_DIR)/get_next_line.c\
	$(SRC_DIR)/get_next_line_utils.c\

OBJ	= $(SRC:.c=.o)


$(NAME): $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^
	@ar crsu $(NAME) $@

all: $(NAME)
		
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all bonus clean fclean re
