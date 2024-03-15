/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:35:29 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/15 10:16:39 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_window_width(t_grid grid, t_plane plane)
{
	int	width;

	if (grid.length == 1 && grid.width == 1)
		width = 100;
	else if (plane.h_marg > 0)
		width = plane.width + (plane.h_marg * 2);
	else
		width = plane.width;
	return (width);
}

static int	get_window_height(t_grid grid, t_plane plane)
{
	int	height;

	if (grid.length == 1 && grid.width == 1)
		height = 50;
	else if (plane.v_marg > 0)
		height = plane.height + (plane.v_marg * 2);
	else
		height = plane.height;
	return (height);
}

static void window_failure(t_xvar *connect, t_plane *plane, t_coord **coord)
{
	free_plane(plane);
	coord_clear(coord);
	mlx_destroy_display(connect);
	free(connect);
	exit (EXIT_FAILURE);
}

void	open_window(t_xvar **connect, t_grid grid, t_plane plane, t_coord **coord)
{
	int	width;
	int	height;

	*connect = mlx_init();
	if (*connect == NULL)
	{
		free_plane(&plane);
		coord_clear(coord);
		exit (1);
	}
	width = get_window_width(grid, plane);
	height = get_window_height(grid, plane);
	(*connect)->win_list = mlx_new_window(*connect, width, height, grid.name);
	if ((*connect)->win_list == NULL)
		window_failure(*connect, &plane, coord);
	mlx_key_hook((*connect)->win_list, &handle_key_input, *connect);
	mlx_hook((*connect)->win_list, 17, 1L << 17, &mlx_loop_end, *connect);
}
