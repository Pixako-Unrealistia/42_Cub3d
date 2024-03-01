# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schongte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 21:26:13 by schongte          #+#    #+#              #
#    Updated: 2022/10/15 23:10:01 by schongte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    =ft_isalpha.c   ft_isdigit.c    ft_isalnum.c ft_isascii.c ft_isprint.c \
                        ft_strlen.c    ft_memset.c     ft_bzero.c   ft_memcpy.c  ft_memmove.c \
                        ft_strlcpy.c   ft_toupper.c    ft_tolower.c ft_strchr.c  ft_strlcat.c \
                        ft_strrchr.c   ft_strncmp.c    ft_memchr.c  ft_memcmp.c  ft_strnstr.c \
                        ft_atoi.c      ft_calloc.c     ft_strdup.c \
                        ft_substr.c    ft_strjoin.c    ft_strtrim.c ft_split.c   ft_itoa.c    \
                        ft_strmapi.c   ft_striteri.c   ft_putchar_fd.c \
                        ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_get_next_line_utils.c ft_get_next_line.c \
						ft_strcmp.c

BONS    =ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
                ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

PRINTF	= 	print_hex.c print_int.c print_ptr.c  print_str.c util_utils.c \
			print_char.c print_usn.c ft_printf.c

OBJS    =$(SRCS:.c=.o)
BOBJ    =$(BONS:.c=.o)
POBJ	=$(PRINTF:.c=.o)


CC              =gcc
RM              =rm -f
CFLAGS  =-Wall -Wextra -Werror -I.

NAME    =libft.a

all:$(NAME) makeprintf 

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus:$(OBJS) $(BOBJ)
	ar rcs $(NAME) $(OBJS) $(BOBJ)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

clean: cleanprintf
	$(RM) $(OBJS) $(BOBJ)

fclean:clean
	$(RM) $(NAME) a.out libft.so

re:fclean $(NAME)

cleanprintf:
	$(RM) $(POBJ)

makeprintf:
	$(CC) -c $(CFLAGS) $(PRINTF)
	ar rcs $(NAME) $(POBJ)

.PHONY:all clean fclean re bonus
