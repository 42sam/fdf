/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_to_canonical.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 08:56:55 by ssachet           #+#    #+#             */
/*   Updated: 2015/02/20 12:30:39 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	switch_term(void)
{
	newterm.c_cc[VMIN] = 1;
	newterm.c_lflag &= ~(ICANON | ECHO);
	newterm.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
	newterm.c_iflag = IGNPAR;
	newterm.c_oflag = 0;
	tcsetattr(0, TCSANOW, &newterm);
}
