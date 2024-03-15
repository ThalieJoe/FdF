/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:37:09 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/14 14:11:25 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_and_exit(int fd, t_coord **coord, char **elem, char *line)
{
	free_tab(elem);
	coord_clear(coord);
	free (line);
	close (fd);
	exit (1);
}

void	clean_and_exit(t_xvar *connect, t_plane *plane, t_coord **coord, int err)
{
	free_plane(plane);
	coord_clear(coord);
	mlx_destroy_window(connect, connect->win_list);
	mlx_destroy_display(connect);
	free(connect);
	if (err)
		exit (EXIT_FAILURE);
}
