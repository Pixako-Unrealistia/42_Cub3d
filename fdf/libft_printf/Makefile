# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 14:21:30 by tnualman          #+#    #+#              #
#    Updated: 2023/09/01 19:14:49 by tnualman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -iquote libft
RM 			= /bin/rm -f

LIBFT_DIR	= ../libft_core_and_diy
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_SRCS	= $(LIBFT_DIR)/srcs

BUILD_DIR	= build
SRC_DIR		= ./srcs
SRCS		= 	ft_printf.c \
				ft_printf_info.c \
				ft_printf_process_specifier.c \
				ft_printf_process_c.c \
				ft_printf_process_d.c \
				ft_printf_process_p.c \
				ft_printf_process_s.c \
				ft_printf_process_u.c \
				ft_printf_process_x.c \
				ft_printf_process_int_precision.c \
				ft_printf_process_width.c \
				ft_printf_process_width_left.c \
				ft_printf_process_width_right.c \
				ft_signed_tostr_base10.c \
				ft_strrev.c \
				ft_unsigned_tostr_base10.c \
				ft_unsigned_tostr_base16.c \
				ft_dprintf.c \
				ft_dprintf_process_c.c \

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "Linking $@"
	@ar rc $(NAME) $(OBJS)
	@echo "Done!"

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -I $(LIBFT_SRCS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

bonus: all

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) -r $(BUILD_DIR)

fclean:
	make fclean -C $(LIBFT_DIR)
	$(RM) -r $(BUILD_DIR)
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re