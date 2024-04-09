# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 13:11:41 by tnualman          #+#    #+#              #
#    Updated: 2023/10/03 10:47:43 by tnualman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -iquote libft
RM 			= /bin/rm -f

BUILD_DIR	= build
SRC_DIR		= ./srcs
SRCS		= ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strlen.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strnstr.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_atol.c\
	diy_str_isnum.c\
	diy_is_in_int.c\
	diy_free_then_null.c\
	diy_free_2ptr_char.c\
	ft_isspace.c\
	diy_str_isspace.c\
	ft_word_count.c\
	ft_split_wc.c\
	get_next_line.c\
	diy_free_2ptr_int.c\
	ft_split_cs.c\
	ft_split_cs_wc.c\
	ft_atoui_hex.c\
	diy_int_sign.c\
	ft_abs_int.c\

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $@"
	@ar -rcs $(NAME) $(OBJS)
	@echo "Done!"

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS)  -c $< -o $@

bonus: all

clean:
	$(RM) -r $(BUILD_DIR)

fclean:
	$(RM) -r $(BUILD_DIR)
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re