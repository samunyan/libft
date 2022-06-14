/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:28:18 by samunyan          #+#    #+#             */
/*   Updated: 2022/04/04 13:28:19 by samunyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"

# define BUFFER_SIZE	128

# define BASE_16_LOW			"0123456789abcdef"
# define BASE_16_UP				"0123456789ABCDEF"
# define BASE_10				"0123456789"
# define BASE_2					"01"

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_islower(int c);

int		ft_toupper(int c);
int		ft_tolower(int c);

size_t	ft_strlen(const char *s);
size_t	ft_strnlen(const char *s, size_t maxlen);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
int		atoi_is_valid(int i, const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strndup(char const *s, size_t len);
char	*ft_append(char **dst, const char *src);
char	*ft_append_until(char **dst, const char *src, size_t n);
char	*ft_prepend(char **dst, const char *src);

char	*ft_skip_space(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnjoin(char const *s1, char const *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_ltoa(long n);
char	*ft_utoa_base(unsigned int n, char *base);
char	*ft_ultoa_base(unsigned long n, char *base);
char	*ft_ulltoa_base(unsigned long long n, char *base);
size_t	ft_get_num_len(unsigned long long n, unsigned int radix);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	*ft_free_arr_until(void **arr, size_t i);
char	*ft_strupcase(char *str);

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memappend(void **dst, const void *src, size_t dstsize,
			size_t srcsize);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

char	*get_next_line(int fd);

typedef struct s_sl_list
{
	void			*content;
	struct s_sl_list	*next;
}	t_sl_list;

t_sl_list	*ft_sl_lstnew(void *content);
int			ft_sl_lstsize(t_sl_list *lst);
t_sl_list	*ft_sl_lstlast(t_sl_list *lst);
void		ft_sl_lstadd_front(t_sl_list **lst, t_sl_list *new);
void		ft_sl_lstadd_back(t_sl_list **lst, t_sl_list *new);
void		ft_sl_lstdelone(t_sl_list *lst, void (*del)(void*));
void		ft_sl_lstclear(t_sl_list **lst, void (*del)(void*));
void		ft_sl_lstiter(t_sl_list *lst, void (*f)(void *));
t_sl_list	*ft_sl_lstmap(t_sl_list *lst, void *(*f)(void *), void (*del)(void *));


typedef struct	s_cdl_list
{
	void					*content;
	struct s_cdl_list_node	*next;
	struct s_cdl_list_node	*prev;
}	t_cdl_list;

t_cdl_list	*ft_cdl_lstnew(void *content);
size_t		ft_cdl_lstsize(t_cdl_list *lst);
t_cdl_list	*ft_cdl_lstlast(t_cdl_list *lst);
void 		*ft_cdl_lstadd_front(t_cdl_list **lst, t_cdl_list *new);
void 		ft_cdl_lstadd_back(t_cdl_list **lst, t_cdl_list *new);
void 		ft_cdl_lstdelone(t_cdl_list *lst, void (*del)(void*));
void 		ft_cdl_lstclear(t_cdl_list **lst, void (*del)(void*));
void 		ft_cdl_lstiter(t_cdl_list *lst, void (*f)(void *));
t_cdl_list	*ft_cdl_lst_set_sentinel(t_cdl_list *new_sentinel);
t_cdl_list	*ft_cdl_lst_get_sentinel(t_cdl_list *lst);

#endif