# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schongte <schongte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 14:39:46 by schongte          #+#    #+#              #
#    Updated: 2024/03/01 14:39:46 by schongte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#DEP : https://github.com/codam-coding-college/MLX42

# Binary Names:
NAME			= cub3d

# Libft
LIBFT_PATH 		= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

# MLX Variables:
MLX				= libmlx42.a
MLX_PATH		= ./mlx/build
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
SRC_C         = map_utils.c  utils.c initialise_map.c 
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
	MINILIBX_FLAGS  = -L$(MLX_PATH) -Iinclude -lglfw
else
	MINILIBX_FLAGS  = -L$(MLX_PATH) -Iinclude -ldl -lglfw -pthread -lm
endif

$(NAME): $(SRC_O) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_O) $(LIBFT) $(MINILIBX_FLAGS) -o $(NAME)
	@printf "$(_SUCCESS) $(NAME) created.\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/$(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I ./sources -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(LIBFT):
	make -C $(LIBFT_PATH)

all: ${NAME} ${BONUS_NAME}

clean:
	make clean -C ${LIBFT_PATH}
	${RM} ${NAME}
	${RM} -r ${OBJ_DIR}
	@printf "$(_INFO) object files removed.\n"

fclean:
	make clean
	@printf "$(_INFO) $(NAME) removed.\n"

re: fclean all

valgrind: all
	$(VALGRIND) ./$(NAME) ./maps/basic.cub

.PHONY: all clean fclean
