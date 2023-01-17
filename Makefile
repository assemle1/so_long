# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 18:17:23 by astalha           #+#    #+#              #
#    Updated: 2023/01/16 21:40:48 by astalha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	checkers.c checkers_utils.c ft_split.c get_next_line_utils.c get_next_line.c libft1.c parcing.c so_long.c
	
OBJS			= $(SRCS:.c=.o)
CC				= gcc
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -Imlx
MLX				= -Lmlx -lmlx -framework OpenGL -framework AppKit
NAME			= so_long

.PHONY: all clean bonus fclean re

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX) -o $(NAME)

all: $(NAME) 
	
%.o: %.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all