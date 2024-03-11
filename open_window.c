/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:35:29 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/11 16:35:53 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	width = (int)fmin((float)(plane.width + (plane.h_marg * 2)), 1920);
	height = (int)fmin((float)(plane.height + (plane.v_marg * 2)), 1050);
	(*connect)->win_list = mlx_new_window(*connect, 970, 540, grid.name);
	if ((*connect)->win_list == NULL)
	{
		free_plane(&plane);
		clean_and_exit(*connect, 1);
	}
	mlx_key_hook((*connect)->win_list, &handle_key_input, *connect);
	mlx_hook((*connect)->win_list, 17, 1L << 17, &close_window, *connect);
}
