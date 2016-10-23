/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 03:26:02 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 17:52:35 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <dirent.h>
# include <signal.h>
# include <time.h>
# include "get_next_line/get_next_line.h"
# include "printf/ft_printf.h"
# define PATH_MAX 4096
# define N(x) ft_putnbr(x)
# define S(x) ft_putstr(x)
# define E(x) ft_putendl(x)
# define C(x) ft_putchar(x)
# define JOIN ft_sprintf
# define LEN(X) ft_strlen(X)
# define CI(X, Y) char_index(X, Y)
# define DBE(X) E(X)
# define DBS(X) S(X)
# define DBN(X) N(X)

typedef	struct		s_list
{
	char			*name;
	char			*value;
	struct s_list	*next;
	void			*content;
	size_t			content_size;
}					t_list;

typedef	struct		s_dict
{
	char			*name;
	char			*value;
	struct s_list	*next;
}					t_dict;

char				*char_to_str(char c);
int					file_exists(char *path);
char				**ft_strsplit(char const *s, char c);
char				*add_chars_to_str(char *s1, char c, int x);
char				*case_down(char *str);
char				*case_up(char *str);
char				*ft_itoa(int n);
char				*ft_ltoa(long n);
char				*ft_ltrim(char const *s);
char				*ft_rtrim(char const *s);
char				*ft_stpcpy(char *s1, const char *s2);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *s);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*hard_trim(char *s, char c);
char				*makestr(char *str);
char				*pad_left(char *s1, char c, int x);
char				*tab_to_space(char *s);
char				*tr(char *s, char c, char tr);
char				*trim_all(char *s);
char				ft_toupper_for_strmap(char s);
char				ft_toupper_for_strmapi(unsigned int i, char s);
int					ft_atoi(const char *str);
int					char_index(char *str, char c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(unsigned char c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_printf(char *string, ...);
int					ft_sprintf(char **s, char *string, ...);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					has_char_at_end(char *str, char c);
int					has_char_rev(char *str, char c);
int					is_dot(char *str);
int					is_lowercase(char c);
int					is_space_str(char *str);
int					is_uppercase(char c);
int					ft_lstlen(t_list *list);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstsplit(char const *s, char c);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t n);
void				free_and_null(t_list **head);
void				ft_bzero(void *s, size_t n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstcpy(t_list *l1, t_list *l2);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstprint(t_list *head);
void				ft_memdel(void **ap);
void				ft_putarray(char **array);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_toupper_for_striter(char *s);
void				ft_toupper_forstriteri(unsigned int i, char *s);
void				push(t_list **head, t_list *new);
int					is_file(char *path);
int					is_digitstr(char *s);
t_list				*new_dict(char *name, char *value, t_list *next);
char				*get_value(char *name, t_list *node);
int					set_value(char *name, char *value,
												int overwrite, t_list *node);
t_list				*lst_copy(t_list *lst);
int					tablen(char **array);
char				*get_current_dir();
int					strstrcount(char *s1, char *s2);
char				**lst_to_array(t_list *lst);
int					lst_del_node(t_list *to_delete, t_list **head);
int					tab_del_i(char **to_delete, t_list **head);
void				init_signals();
int					is_directory(char *path);
int					is_file(char *path);
#endif
