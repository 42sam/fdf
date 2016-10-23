/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 22:09:20 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/22 16:29:04 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# define BUF_SIZE 1
# define F1	0.6
# define F2	0.5
# define WIN_HEIGHT	1500
# define WIN_WIDTH	2500
# define WIN_SIZE	1400

typedef	struct		s_line
{
	int				**line;
	int				len;
	struct s_line	*next;
}					t_line;

typedef	struct		s_bres
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				e2;
	int				err;
}					t_bres;

typedef	struct		s_env
{
	void			*mlx;
	void			*win;
	t_line			*matrix;
	int				gap;
	int				y0;
	int				x0;
	float			f1;
	float			f2;
	int				h;
	int				max_x;
	int				height;
	int				mnb;
	int				mxb;
	int				scale;
	int				third;
}					t_env;

typedef	struct		s_pix
{
	int				x;
	int				y;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
}					t_pix;

int					**str_array_to_int_array(char **str, t_env *e);
int					expose_hook(t_env *e);
int					iso_x(int y, int x, t_env *e);
int					iso_y(int y, int x, int z, t_env *e);
int					key_hook(int keycode, t_env *e);
int					lstlen(t_line *lst);
int					mouse_hook(int button, int x, int y, t_env *e);
t_line				*get_matrix(int fd, t_env *e);
t_line				*one_line(char *str_line, t_env *e);
void				print_map(t_line *matrix);
t_bres				*new_bres(int x0, int x1, int y0, int y1);
int					trace_line(t_pix *pix, t_env *e);
int					trace_lines(t_line *column, t_env *e);
int					trace_columns(t_line *head, t_env *e);
int					trace_column_call(t_env *e, t_line *line,
														t_pix *pix, int len);
int					trace_line_call(t_env *e, t_line *column,
														t_pix *pix, int len);
void				tracing_improvement(t_bres *b, t_pix *pix);
#endif
