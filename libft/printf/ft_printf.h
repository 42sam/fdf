/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 21:43:31 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 17:25:32 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# define N(x) ft_putnbr(x)
# define S(x) ft_putstr(x)
# define E(x) ft_putendl(x)
# define C(x) ft_putchar(x)
# define VAR_SIZE 1024

typedef struct	s_flag
{
	char		pad;
	char		padchar;
	char		sign;
	char		sign_pad;
	int			longhexaformat;
	int			min_width;
	int			sign_put;
	int			bla;
	char		l_modifier;
	int			precision;
	int			width;
	char		type;
	int			zero;
	int			p_alpha;
	int			fd;
	int			ext_width;
	int			c_zero;
	int			quit_error;
}				t_a;

typedef struct	s_colors
{
	char		name[20];
	char		code[20];
}				t_colors;

char			*add_sign(void *myarg, t_a *flag);
char			*cast_to_c(va_list argp, t_a *flag);
char			*cast_to_id(va_list argp, t_a *flag);
char			*cast_to_numeric(va_list argp, t_a *flag, char *str);
char			*cast_to_o(va_list argp, t_a *flag);
char			*cast_to_oo(va_list argp, t_a *flag);
char			*cast_to_p(va_list argp, t_a *flag);
char			*cast_to_s(va_list argp, t_a *flag);
char			*cast_to_str(va_list argp, t_a *flag);
char			*cast_to_str(va_list argp, t_a *flag);
char			*cast_to_u(va_list argp, t_a *flag);
char			*cast_to_uu(va_list argp);
char			*cast_to_wc(va_list argp, t_a *flag);
char			*cast_to_ws(va_list argp, t_a *flag);
char			*cast_to_x(va_list argp, t_a *flag);
char			*ft_itox(size_t n);
char			*ft_itox2(int n, int base);
char			*ft_ltoap(size_t n);
char			*ft_ltox(size_t n);
char			*ft_stoa(size_t n);
char			*ft_stoo2(size_t number_to_convert, int base);
char			*ft_strrev(char *s);
char			*ft_uppercase(char *str);
char			*pad_left(char *s1, char c, int x);
char			*pad_right(char *s1, char c, int x);
int				add_l_modifiers(char **str, t_a *flag);
int				add_precision(char **str, t_a *flag);
int				add_type(char **str, t_a *flag);
int				add_width(char **str, t_a *flag);
int				char_conversion(t_a *flag);
int				ft_printf(char *string, ...);
int				hexa_conversion(t_a *flag);
int				is__dot(int c);
int				is_error_type(char c);
int				is_flag(char c);
int				is_l_modifier(char c);
int				is_type(char c);
int				is_valid(char c);
int				no_conversion(t_a *flag);
int				numeric_conversion(t_a *flag);
int				octal_conversion(t_a *flag);
int				pointer_conversion(t_a *flag);
int				precision_atoi(const char *str);
int				string_conversion(t_a *flag);
size_t			ft_atos(const char *str);
size_t			ft_stoo(size_t n);
t_a				*add_flags(char **str, t_a *flag);
t_a				*new_a(void);
t_colors		*load_colors(void);
void			*apply_left_width_char(void *myarg, t_a *flag, int width);
void			*apply_left_width_hexa(void *myarg, t_a *flag, int width);
void			*apply_left_width_numeric(void *myarg, t_a *flag, int width);
void			*apply_left_width_pointer(void *myarg, t_a *flag, int width);
void			*apply_left_width_simple(void *myarg, t_a *flag, int width);
void			*apply_precision(void *myarg, t_a *flag);
void			*apply_sign(void *myarg, t_a *flag);
void			*apply_width(void *myarg, t_a *flag);
void			*apply_zerox(void *myarg, t_a *flag);
void			add_ext_width(va_list argp, t_a *flag);
void			add_format(char **str, t_a *flag);
void			apply_colors(char **string, t_colors *color, char **variable);
void			print_escape(char **str);
void			utf_21_bits(wchar_t c, char **b);
void			wc_conversion(wchar_t c, char **b);
wchar_t			*wchar_to_str(wchar_t c);
void			sprint_escape(char **str, char *variable);
int				ft_sprintf(char **variable, char *string, ...);
void			*apply_all(void *myarg, t_a *flag);
#endif
