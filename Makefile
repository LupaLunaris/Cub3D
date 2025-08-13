# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Jpaulis <Jpaulis@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 00:00:00 by Jpaulis           #+#    #+#              #
#    Updated: 2025/08/13 00:00:00 by Jpaulis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCDIR = srcs
OBJDIR = objs
INCDIR = includes
LIBFTDIR = libft
MLXDIR = minilibx-linux

INCLUDES = -I$(INCDIR) -I$(LIBFTDIR) -I$(MLXDIR)

SRCS = $(SRCDIR)/main.c \
       $(SRCDIR)/player_move.c \
       $(SRCDIR)/player_rotate.c \
       $(SRCDIR)/raycasting.c \
       $(SRCDIR)/utils.c \
       $(SRCDIR)/error_handling.c \
       $(SRCDIR)/cleanup.c \
       $(SRCDIR)/cleanup2.c \
       $(SRCDIR)/key_events.c \
       $(SRCDIR)/init_game.c \
       $(SRCDIR)/init_textures.c \
       $(SRCDIR)/parser.c \
       $(SRCDIR)/verif.c \
       $(SRCDIR)/math.c \
       $(SRCDIR)/render.c \
       $(SRCDIR)/render_utils.c \
       $(SRCDIR)/parse_textures.c \
       $(SRCDIR)/parse_colors.c \
       $(SRCDIR)/parse_map_utils.c \
       $(SRCDIR)/parse_map_build.c \
       $(SRCDIR)/parse_map_free.c \
       $(SRCDIR)/parse_player.c \
       $(SRCDIR)/map_loader.c \
       $(SRCDIR)/parse_map.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)/libmlx.a

LIBS = -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx -lXext -lX11 -lm

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFTDIR)

$(MLX):
	@make -C $(MLXDIR)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean
	@make -C $(MLXDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all