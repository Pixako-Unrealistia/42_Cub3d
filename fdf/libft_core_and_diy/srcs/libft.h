/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnualman <tnualman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:02:23 by tnualman          #+#    #+#             */
/*   Updated: 2023/10/03 11:02:06 by tnualman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

/* Mandatory Libc functions */
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);

void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);

/* Mandatory Libc functions, with malloc authorized */
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);

/* Mandatory additional functions */
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/* Additional functions since push_swap */

int				ft_isspace(int c);
long			ft_atol(const char *str);
int				diy_str_isnum(const char *str);
int				diy_str_isspace(const char *str);
int				diy_is_in_int(long n);
void			diy_free_then_null(void **ptr);
void			diy_free_2ptr_char(char **array_s);

/* Additional functions since fdf */

size_t			ft_word_count(char const *s, char c);
char			**ft_split_wc(char const *s, char c, size_t *wordcount);
char			*get_next_line(int fd);
void			diy_free_2ptr_int(int **double_ptr_int,
					size_t inner_malloc_count);
char			**ft_split_cs(char const *s, char *charset);
char			**ft_split_cs_wc(char const *s, char *charset,
					size_t *wordcount);
unsigned int	ft_atoui_hex(const char *str);
int				diy_int_sign(int value);
int				ft_abs_int(int value);

#endif