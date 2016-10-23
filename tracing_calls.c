/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing_calls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 16:22:03 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/22 11:59:37 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		trace_line(t_pix *pix, t_env *e)
{
	t_bres	*b;

	if ((b = new_bres(pix->x0, pix->x1, pix->y0, pix->y1)) == NULL)
		return (-1);
	while (42)
	{
		if (e->height < (e->scale / 3))
			mlx_pixel_put(e->mlx, e->win, pix->x0, pix->y0, 0x046380);
		else if (e->height < ((e->scale / 3) * 2))
			mlx_pixel_put(e->mlx, e->win, pix->x0, pix->y0, 0x8FCF3C);
		else
			mlx_pixel_put(e->mlx, e->win, pix->x0, pix->y0, 0x00FFFF);
		if (pix->x0 == pix->x1 && pix->y0 == pix->y1)
			break ;
		tracing_improvement(b, pix);
	}
	return (0);
}

int		trace_line_call(t_env *e, t_line *column, t_pix *pix, int len)
{
	e->height = *column->line[len];
	pix->x0 = iso_x(pix->y, pix->x, e);
	pix->y0 = iso_y(pix->y, pix->x, *column->line[len] * e->h, e);
	pix->x1 = iso_x(pix->y, pix->x + e->gap, e);
	pix->y1 = iso_y(pix->y, pix->x + e->gap, *column->line[len + 1] * e->h, e);
	if ((trace_line(pix, e)) == -1)
		return (-1);
	return (0);
}

int		trace_lines(t_line *column, t_env *e)
{
	int		len;
	t_pix	*pix;

	if ((pix = (t_pix *)malloc(sizeof(t_pix))) == NULL)
		return (-1);
	pix->y = e->y0;
	while (column)
	{
		pix->x = e->x0;
		len = 0;
		while ((len < column->len - 1))
		{
			if (column->line[len] && column->line[len + 1])
			{
				trace_line_call(e, column, pix, len);
			}
			pix->x += e->gap;
			len++;
		}
		pix->y += e->gap;
		column = column->next;
	}
	return (0);
}

int		trace_column_call(t_env *e, t_line *line, t_pix *pix, int len)
{
	e->height = *line->line[len];
	pix->x0 = iso_x(pix->y, pix->x, e);
	pix->y0 = iso_y(pix->y, pix->x, *line->line[len] * e->h, e);
	pix->x1 = iso_x(pix->y + e->gap, pix->x, e);
	pix->y1 = iso_y(pix->y + e->gap, pix->x,
			*(line->next)->line[len] * e->h, e);
	if ((trace_line(pix, e)) == -1)
		return (-1);
	return (0);
}

int		trace_columns(t_line *head, t_env *e)
{
	int		len;
	t_line	*line;
	t_pix	*pix;

	if ((pix = (t_pix *)malloc(sizeof(t_pix))) == NULL)
		return (-1);
	len = 0;
	pix->x = e->x0;
	line = head;
	while (len < line->len)
	{
		pix->y = e->y0;
		while (line)
		{
			if ((line->next) && (len < line->len) && (len < (line->next)->len))
				trace_column_call(e, line, pix, len);
			pix->y += e->gap;
			line = line->next;
		}
		line = head;
		len++;
		pix->x += e->gap;
	}
	return (0);
}
