/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <fjewfish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 18:27:06 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/11 20:12:17 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "printf/includes/all.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char		*ft_join_bufpart(char **bufpart, char **eol);
int			ft_what_to_return(int length_b, char **bufpart, int case_1);
int			get_next_line(int fd, char **line);
char		*gnl_ft_strchr(const char *aio);

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset (void *destination, int c, size_t n);
void				ft_bzero(void *aio, size_t n);
void				*ft_memcpy(void *restrict s1,
								const void *restrict s2, size_t n);
void				*ft_memccpy(void *restrict s1,
								const void *restrict s2, int c, size_t n);
void				*ft_memmove(void *aio1, const void *aio2, size_t n);
void				*ft_memchr(const void *aio, int c, size_t n);
int					ft_memcmp(const void *aio1, const void *aio2, size_t n);
size_t				ft_strlen(const char *aio);
size_t				ft_strlcpy(char *dst, const char *aiorc, size_t size);
char				*ft_strcpy(char *dest, char *aiorc);
size_t				ft_strlcat(char *dst, const char *aiorc, size_t size);
char				*ft_strchr(const char *aio, int c);
char				*ft_strrchr(const char *aio, int c);
char				*ft_strnstr(const char *aio1, const char *aio2, size_t n);
int					ft_strncmp(const char *aio1, const char *aio2, size_t n);
int					ft_atoi(char *aiotr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *aio1);
char				*ft_substr(char const *aio, unsigned int start, size_t len);
char				*ft_strjoin(char const *aio1, char const *aio2);
char				*ft_strtrim(char const *aio1, char const *aioet);
char				**ft_split(char const *aio, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *aio, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *aio, int fd);
void				ft_putendl_fd(char *aio, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
								void (*del)(void *));

#endif
