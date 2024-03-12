/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:35:29 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/12 17:10:09 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_window_width(t_plane plane)
{
	int	width;

	if (plane.h_marg > 0)
		width = plane.width + (plane.h_marg * 2);
	else
		width = plane.width;
	return (width);
}

static int	get_window_height(t_plane plane)
{
	int	height;

	if (plane.v_marg > 0)
		height = plane.height + (plane.v_marg * 2);
	else
		height = plane.height;
	return (height);
}

void	open_window(t_xvar **connect, t_grid grid, t_plane plane)
{
	int	width;
	int	height;

	*connect = mlx_init();
	if (*connect == NULL)
	{
		free_plane(&plane);
		clean_and_exit(*connect, 1);
	}
	width = get_window_width(plane);
	height = get_window_height(plane);
	// width = (int)fmin((float)(plane.width + (plane.h_marg * 2)), 1920);
	// height = (int)fmin((float)(plane.height + (plane.v_marg * 2)), 1050);
	(*connect)->win_list = mlx_new_window(*connect, width, height, grid.name);
	if ((*connect)->win_list == NULL)
	{
		free_plane(&plane);
		clean_and_exit(*connect, 1);
	}
	mlx_key_hook((*connect)->win_list, &handle_key_input, *connect);
	mlx_hook((*connect)->win_list, 17, 1L << 17, &close_window, *connect);
}
