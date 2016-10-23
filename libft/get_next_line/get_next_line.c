/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 11:47:57 by ssachet           #+#    #+#             */
/*   Updated: 2015/01/22 20:05:50 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char *str, size_t size)
{
	char		*ptr;

	if (NULL == (ptr = ft_strnew(size)))
		return (NULL);
	ft_strcpy(ptr, str);
	free(str);
	str = NULL;
	return (ptr);
}

int		has_char(char *str, char c)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		emptyline(char **line, char **rush)
{
	if (ft_strlen(*rush) > 1)
	{
		if ((*rush = ft_strsub(*rush, 1, ft_strlen(*rush) - 1)) == NULL)
			return (-1);
	}
	else
		*rush = ft_strnew(1);
	*line = ft_strnew(1);
	return (1);
}

int		read_new_line(t_var *s, char **line, char **rush)
{
	char		buf[BUFF_SIZE + 1];

	if (s->fd == -1)
	{
		*line = NULL;
		return (-1);
	}
	if (!*rush)
		if ((*rush = ft_strnew(0)) == NULL)
			return (-1);
	while ((s->n == -1) && (s->rd == BUFF_SIZE) && **rush != '\n')
	{
		s->rd = read(s->fd, buf, BUFF_SIZE);
		buf[s->rd] = '\0';
		if ((NULL == (*rush = ft_realloc(*rush, ft_strlen(*rush) + s->rd + 1))))
			return (-1);
		*rush = ft_strcat(*rush, buf);
		s->n = has_char(*rush, '\n');
	}
	if (**rush == '\n')
		return (((emptyline(line, rush)) == -1) ? -1 : 1);
	s->n = (s->n == -1) ? (int)ft_strlen(*rush) : s->n;
	if ((*line = ft_strsub(*rush, 0, s->n)) == NULL)
		return (0);
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	t_var		s;
	static char	*rush;
	int			read;

	s.n = -1;
	s.rd = BUFF_SIZE;
	s.fd = fd;
	if ((read = read_new_line(&s, line, &rush)) == -1)
		return (-1);
	if (read == 1)
		return (1);
	if (s.n != (int)ft_strlen(rush))
	{
		if ((rush = (char *)ft_strsub(rush, s.n + 1,
						ft_strlen(rush) - s.n - 1)) == NULL)
			return (0);
	}
	else
	{
		free(rush);
		rush = NULL;
	}
	if (s.rd != BUFF_SIZE)
		return ((*line && (ft_strlen(*line) > 0)) ? 1 : 0);
	return (1);
}
