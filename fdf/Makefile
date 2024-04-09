# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 22:04:57 by tnualman          #+#    #+#              #
#    Updated: 2023/10/15 14:13:19 by tnualman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS =	-Werror -Wextra -Wall #-fsanitize=address

NAME =			fdf
BUILD_DIR =		build
SRC_DIR	=		srcs
SRC =			fdf_main.c \
				fdf_create_maps.c \
				fdf_map_fill_utils.c \
				fdf_free.c \
				fdf_error.c \
				fdf_window.c \
				fdf_draw.c \
				fdf_draw_line.c \
				fdf_rotate.c \
				fdf_projection.c \
				fdf_keyboard_handle.c
HEADER =		srcs/fdf.h

NAME_CRAZY =		fdf_crazy
BUILD_DIR_CRAZY =	build_crazy
SRC_DIR_CRAZY	=	srcs_crazy
SRC_CRAZY =			fdf_main.c \
					fdf_create_maps.c \
					fdf_map_fill_utils.c \
					fdf_free.c \
					fdf_error.c \
					fdf_window.c \
					fdf_draw.c \
					fdf_draw_line.c \
					fdf_rotate.c \
					fdf_projection.c \
					fdf_keyboard_handle.c
HEADER_CRAZY =		srcs_crazy/fdf.h

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	MLX_DIR =	minilibx_linux
	INCLUDES =	libft_printf/libftprintf.a \
				$(MLX_DIR)/libmlx.a
	MLX_FLAGS =	-Iminilibx_linux -Lminilibx_linux -lXext -lX11 -lm -lz
else
	MLX_DIR =	minilibx_macos
	INCLUDES =	libft_printf/libftprintf.a \
				$(MLX_DIR)/libmlx.a
	MLX_FLAGS =	-L$(MLX_DIR) \
				-framework OpenGL \
				-framework AppKit
endif

OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)
OBJ_CRAZY = $(SRC_CRAZY:%.c=$(BUILD_DIR_CRAZY)/%.o)

all: $(NAME)

bonus: all

crazy: $(NAME_CRAZY)

$(NAME): $(OBJ)
	make -C libft_printf/ all
	make -C $(MLX_DIR)/ all
	$(CC) $(FLAGS) $(OBJ) $(INCLUDES) -I$(HEADER) $(MLX_FLAGS) -o $(NAME)
	@echo "Done!"

$(OBJ): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS)  -c $< -o $@

$(NAME_CRAZY): $(OBJ_CRAZY)
	make -C libft_printf/ all
	make -C $(MLX_DIR)/ all
	$(CC) $(FLAGS) $(OBJ_CRAZY) $(INCLUDES) -I$(HEADER) $(MLX_FLAGS) \
		-o $(NAME_CRAZY)
	@echo "Done!"

$(OBJ_CRAZY): $(BUILD_DIR_CRAZY)/%.o: $(SRC_DIR_CRAZY)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS)  -c $< -o $@

clean:
	@make -C libft_printf/ clean
	@make -C $(MLX_DIR)/ clean
	rm -rf build
	rm -rf build_crazy
	rm -rf fdf.dSYM

fclean:
	@make -C libft_printf/ fclean
	@make -C $(MLX_DIR)/ clean
	rm -rf build
	rm -rf build_crazy
	rm -rf fdf.dSYM
	rm -f $(NAME)
	rm -f $(NAME_CRAZY)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus crazy
