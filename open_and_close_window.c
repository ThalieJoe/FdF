/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_close_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:35:29 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/06 17:11:04 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_xvar **connect)
{
	mlx_loop_end(*connect);
	mlx_destroy_window(*connect, (*connect)->win_list);
	return (0);
}

void	open_window(t_xvar **connect, t_map map, t_plane plane)
{
	int	width;
	int	height;

	*connect = mlx_init();
	if (*connect == NULL)
		clean_and_exit(*connect, &plane, 1);
	width = (int)fmin((float)(plane.width + (plane.margin_abs * 2)), 1920);
	height = (int)fmin((float)(plane.height + (plane.margin_ord * 2)), 1050);
	(*connect)->win_list = mlx_new_window(*connect, 1500, 550, map.name);
	if ((*connect)->win_list == NULL)
		clean_and_exit(*connect, &plane, 1);
	mlx_key_hook((*connect)->win_list, &handle_key_input, connect);
	// mlx_hook((*connect)->win_list, 2, 1L << 0, &close_window, connect);
	mlx_hook((*connect)->win_list, 17, 1L << 17, &close_window, connect);
}


// void	open_window(t_xvar **connect, t_file *infos, int width, int height)
// {
// 	height += infos->win_margin * 2;
// 	width += infos->win_margin * 2;
// 	*connect = mlx_init();
// 	if (*connect == NULL)
// 		exit (1);
// 	(*connect)->win_list = mlx_new_window(*connect, width, height, infos->name);
// 	if ((*connect)->win_list == NULL)
// 	{
// 		mlx_destroy_display(*connect);
// 		free(*connect);
// 		exit (1);
// 	}
// }

// int	close_window(t_xvar **connect)
// {
// 	mlx_loop_end(*connect);
// 	mlx_destroy_window(*connect, (*connect)->win_list);
// 	return (0);
// }
