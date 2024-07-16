# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 14:39:46 by schongte          #+#    #+#              #
#    Updated: 2024/07/07 22:58:35 by tnualman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#DEP : https://github.com/codam-coding-college/MLX42

# Binary Names:
NAME			= cub3D

# Libft
LIBFT_PATH 		= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

# MLX Variables:
MLX				= libmlx42.a
MLX_PATH		= ./
INCLUDES 		= -Imlx -I$(MLX_PATH)

# Compiling Variables:
CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra -g
RM 				= rm -f
VALGRIND		= valgrind --leak-check=full --show-leak-kinds=all \
				--track-origins=yes --tool=memcheck

# Source Files:
SRC_DIR       = ./sources
OBJ_DIR       = ./objects
SRC_C         = main.c \
				key_hook.c \
				free_utils.c \
				player_movement.c \
				draw_line.c \
				draw_line_utils.c \
				raycast_math_utils.c \
				raycast_utils.c \
				raycast_1ray.c \
				raycast_wall.c \
				raycast.c \
				parser_utils.c \
				parser_map_utils.c \
				initialise_map.c \
				parser_validators.c \
				parser_map_corrections.c \
				parser_color.c \
				parser_map_reader.c

# Map Files:
MAP_DIR			= ./maps
MAP_C			= invalid_bad_letter.cub \
				invalid_basic.cub \
				invalid_double_colour.cub \
				invalid_double_declare.cub \
				invalid_double_start.cub \
				invalid_empty_middle.cub \
				invalid_no_border.cub \
				invalid_no_border_non-edges.cub \
				invalid_no_header.cub \
				invalid_four_colour.cub \
				invalid_two_colour.cub

SRC_O         = $(addprefix $(OBJ_DIR)/, $(SRC_C:.c=.o))
HEADER    	  = cub3d.h

# Colors:
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RED			=	\e[38;5;196m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]


ifeq ($(shell uname), Darwin)
	MINILIBX_FLAGS  = -L$(MLX_PATH) -Iinclude
else
	MINILIBX_FLAGS  = -L$(MLX_PATH) -Iinclude -ldl -lglfw -pthread -lm
endif

$(NAME): $(SRC_O) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(SRC_O) $(LIBFT) $(MLX) $(MINILIBX_FLAGS) -o $(NAME)
	@printf "$(_SUCCESS) $(NAME) created.\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/$(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I ./sources -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(LIBFT):
	make -C $(LIBFT_PATH)

all: ${NAME} ${BONUS_NAME} ${LIBFT}

clean:
	make clean -C ${LIBFT_PATH}
	${RM} ${NAME}
	${RM} -r ${OBJ_DIR}
	@printf "$(_INFO) object files removed.\n"

fclean:
	make clean
	make fclean -C ${LIBFT_PATH}
	@printf "$(_INFO) $(NAME) removed.\n"

re: fclean all

.PHONY: all clean fclean

test: all
	@printf "$(_INFO) Testing maps...\n"
	@for map in $(MAP_C); do \
		printf "$(_INFO) Testing $$map\n"; \
		./$(NAME) $(MAP_DIR)/$$map; \
	done

v_test: all
	@printf "$(_INFO) Testing maps...\n"
	@for map in $(MAP_C); do \
		printf "$(_INFO) Testing $$map\n"; \
		$(VALGRIND) ./$(NAME) $(MAP_DIR)/$$map; \
	done