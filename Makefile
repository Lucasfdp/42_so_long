# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luferna3 <luferna3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/08 03:35:32 by luferna3          #+#    #+#              #
#    Updated: 2025/06/16 07:17:26 by luferna3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
NAME = so_long

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

SRC_DIR = src
SRCS = $(SRC_DIR)/parsing.c $(SRC_DIR)/map_handling.c $(SRC_DIR)/pathing.c\
		$(SRC_DIR)/images.c $(SRC_DIR)/preparing.c $(SRC_DIR)/movement.c $(SRC_DIR)/main.c

OBJ_FILES = $(SRCS:$(SRC_DIR)/%.c=%.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBFT) $(MLX)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ_FILES)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
