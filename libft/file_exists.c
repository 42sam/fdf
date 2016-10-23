/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 08:15:20 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 12:30:38 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		file_exists(char *path)
{
	struct stat		details;

	lstat(path, &details);
	if ((details.st_mode & S_IFMT) == S_IFDIR)
		return (1);
	else if ((details.st_mode & S_IFMT) == S_IFLNK)
		return (1);
	else if ((details.st_mode & S_IFMT) == S_IFCHR)
		return (1);
	else if ((details.st_mode & S_IFMT) == S_IFBLK)
		return (1);
	else if ((details.st_mode & S_IFMT) == S_IFSOCK)
		return (1);
	else if ((details.st_mode & S_IFMT) == S_IFIFO)
		return (1);
	else if ((details.st_mode & S_IFMT) == S_IFWHT)
		return (1);
	else if ((details.st_mode & S_IFMT) == S_IFREG)
		return (1);
	return (0);
}
