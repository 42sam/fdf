/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 09:44:16 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/19 09:47:13 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_directory(char *path)
{
	struct stat		details;

	lstat(path, &details);
	if ((details.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	return (0);
}
