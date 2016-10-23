/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:09:04 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/22 11:59:37 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *e)
{
	trace_lines(e->matrix, e);
	trace_columns(e->matrix, e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	else if (keycode == 65362)
		e->gap = (e->gap < 700) ? e->gap + 10 : e->gap;
	else if (keycode == 65364)
		e->gap = (e->gap > 10) ? e->gap - 10 : e->gap;
	else if (keycode == 106)
		e->y0 = (e->y0 < 500) ? e->y0 + 100 : e->y0;
	else if (keycode == 107)
		e->y0 = (e->y0 > -1000) ? e->y0 - 100 : e->y0;
	else if (keycode == 108)
		e->x0 += 100;
	else if (keycode == 104)
		e->x0 -= 100;
	else if (keycode == 112)
		e->h = (e->h > -32) ? e->h * 2 : e->h;
	else if (keycode == 110)
		e->h = (e->h < -1) ? e->h / 2 : e->h;
	mlx_clear_window(e->mlx, e->win);
	trace_lines(e->matrix, e);
	trace_columns(e->matrix, e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	(void)e;
	(void)x;
	(void)y;
	(void)button;
	return (0);
}

t_line	*get_matrix(int fd, t_env *e)
{
	char	*line;
	t_line	*matrix;
	t_line	*node;
	int		getreturn;

	getreturn = 0;
	e->max_x = 0;
	if ((get_next_line(fd, &line)) == -1)
		return (NULL);
	if ((matrix = one_line(line, e)) == NULL)
		return (NULL);
	node = matrix;
	while ((getreturn = get_next_line(fd, &line)) > 0)
	{
		if ((node->next = one_line(line, e)) == NULL)
			return (NULL);
		node = node->next;
	}
	if (getreturn == -1)
		return (NULL);
	e->scale = abs(e->mnb) + abs(e->mxb);
	e->third = e->scale / 3;
	if (close(fd) == -1)
		return (NULL);
	return (matrix);
}
