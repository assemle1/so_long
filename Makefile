# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 18:17:23 by astalha           #+#    #+#              #
#    Updated: 2023/01/23 01:35:52 by astalha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_Mandatory	=	Mandatory/checkers.c Mandatory/checkers_utils.c Mandatory/ft_split.c Mandatory/get_next_line_utils.c Mandatory/get_next_line.c Mandatory/libft1.c Mandatory/parcing.c Mandatory/so_long.c Mandatory/valid_path.c Mandatory/ft_printf.c Mandatory/ft_printf_utils.c Mandatory/make_img.c\
					Mandatory/movs.c Mandatory/start.c

SRCS_Bonus		=	bonus/checkers_bonus.c bonus/checkers_utils_bonus.c bonus/ft_split_bonus.c bonus/get_next_line_utils_bonus.c bonus/get_next_line_bonus.c bonus/libft1_bonus.c bonus/parcing_bonus.c bonus/so_long_bonus.c bonus/valid_path_bonus.c bonus/ft_printf_bonus.c bonus/ft_printf_utils_bonus.c bonus/make_img_bonus.c\
					bonus/movs_bonus.c bonus/start_bonus.c bonus/movs_enemy.c bonus/ft_itoa.c bonus/enemy.c bonus/print.c

OBJS			= $(SRCS_Mandatory:.c=.o)
OBJS_B			= $(SRCS_Bonus:.c=.o)
CC				= gcc
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -Imlx
MLX				= -lmlx -framework OpenGL -framework AppKit
NAME			= Mandatory/so_long
NAME_B			= bonus/so_long

.PHONY: all clean bonus fclean re

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX) -o $(NAME)

$(NAME_B): $(OBJS_B)
	$(CC) $(OBJS_B) $(MLX) -o $(NAME_B)

all: $(NAME) 

bonus: $(NAME_B)

%.o: %.c src/so_long.h src/bonus.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean:	clean
	$(RM) $(NAME) $(NAME_B)

re: fclean all