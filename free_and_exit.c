/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:37:44 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 13:42:36 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_and_exit(int fd, t_coord **coord, char **elem, char *line)
{
	free_tab(elem);
	coord_clear(coord);
	free (line);
	close (fd);
	exit (EXIT_FAILURE);
}
