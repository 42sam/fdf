/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 20:51:04 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/22 11:59:37 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		error_check(int ac, char **av)
{
	int		fd;

	if (ac == 1)
	{
		ft_printf("fdf: Need one argument");
		return (-1);
	}
	else if (ac > 2)
	{
		ft_printf("fdf: Need only one argument");
		return (-1);
	}
	if ((fd = open (av[1], O_RDWR | O_APPEND)) == -1)
	{
		perror("fdf");
		return (-1);
	}
	return (fd);
}

int		get_gap(t_line *matrix, int max_x)
{
	int		max_size;
	int		gap;

	max_size = (lstlen(matrix) > max_x) ? lstlen(matrix) : max_x;
	gap = (WIN_SIZE / (max_size * 1.5));
	return (gap);
}

t_env	*init_env(void)
{
	t_env	*e;

	if ((e = (t_env *)malloc(sizeof(t_env))) == NULL)
		return (NULL);
	e->y0 = 1;
	e->x0 = 1200;
	e->f1 = 0.6;
	e->f2 = 0.5;
	e->h = -4;
	e->max_x = 0;
	e->mnb = 0;
	e->mxb = 0;
	return (e);
}

int		main(int ac, char **av)
{
	int		fd;
	t_env	*e;

	if ((e = init_env()) == NULL)
		return (-1);
	if ((fd = (error_check(ac, av))) == -1)
		return (0);
	if ((e->matrix = get_matrix(fd, e)) == NULL)
		return (-1);
	e->gap = get_gap(e->matrix, e->max_x);
	if ((e->mlx = mlx_init()) == NULL)
	{
		ft_printf("fdf : env error\n");
		return (0);
	}
	e->win = mlx_new_window(e->mlx, WIN_WIDTH, WIN_HEIGHT, "fdf rocks");
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_clear_window(e->mlx, e->win);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
