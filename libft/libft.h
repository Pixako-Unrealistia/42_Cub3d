/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pix <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:44:16 by pix               #+#    #+#             */
/*   Updated: 2023/04/04 20:17:19 by schongte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include "ft_printf.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int arg);
int		ft_isdigit(int arg);
int		ft_isalnum(char arg);
int		ft_isascii(int arg);
int		ft_isprint(int arg);
size_t	ft_strlen(const char *arg);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
int		ft_strncmp(const char *dest, const char *src, size_t n);
int		ft_atoi(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
int		ft_toupper(int chr);
int		ft_tolower(int chr);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strnstr(const char *str, const char *c, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
int		ft_strcmp(const char *dest, const char *src);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char const *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*get_next_line(int fd);
int		super_get_next_line(int fd, char **line);
void	*util_memset(void *str, int c, size_t n);
char	*util_strjoin(char const *s1, char const *s2);
void	*util_calloc(size_t nitems, size_t size);
size_t	util_strlen(char *str);
char	*util_strchr(const char *str, int c);
void	*main_free(char *s1, char *s2);
char	*main_parse_next(char *s);
char	*main_parse_line(char *s);

#endif
