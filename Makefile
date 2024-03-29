#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 15:19:53 by parnaldo          #+#    #+#              #
#    Updated: 2022/11/01 14:32:19 by parnaldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NBONUS = fractol_bonus
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Ofast

SRC =  main.c \
	   controls.c \
	   draw.c \
	   julia.c \
	   paint.c \
	   mandelbrot.c \
	   message.c \
	   burningship.c

SRC_BONUS =  main_bonus.c \
	   controls_bonus.c \
	   draw_bonus.c \
	   julia_bonus.c \
	   paint_bonus.c \
	   mandelbrot_bonus.c \
	   message_bonus.c \
	   burningship_bonus.c

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

# LIBFT #
LIBFT = ./libs/libft/libft.a
LIBFT_DIR = ./libs/libft

INC_LIBFT = -I. -I$(LIBFT_DIR)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

detected_OS := $(shell uname)
ifeq ($(detected_OS),Linux)
$(NAME): $(OBJS) $(LIBFT)
	@$(MAKE) -C mlx_linux all
	@cp ./mlx_linux/libmlx.a .
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INC_LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
##instruções para linux
else
$(NAME): $(OBJS) $(LIBFT)
	@$(MAKE) -C mlx all
	@cp ./mlx/libmlx.a .
	@$(CC) $(CFLAGS) -g -o $(NAME) $(OBJS) $(LIBFT) $(INC_LIBFT) -Lmlx -lmlx  -framework OpenGL -framework AppKit
	@echo "Compilation fractol"
##instruções para mac
endif

bonus: $(OBJS_BONUS) $(LIBFT)
	@$(MAKE) -C mlx all
	@cp ./mlx/libmlx.a .
	@$(CC) $(CFLAGS) -g -o $(NBONUS) $(OBJS_BONUS) $(LIBFT) $(INC_LIBFT) -Lmlx -lmlx  -framework OpenGL -framework AppKit
	@echo "Compilation fractol_bonus"

$(LIBFT):
		@$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

clean:
	$(MAKE) -C mlx clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) *.o

fclean: clean
	$(RM) libmlx.a
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(NBONUS)

re: fclean all

.PHONY: all clean fclean re
