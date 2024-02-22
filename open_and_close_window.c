/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_close_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:35:29 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/21 11:11:30 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	open_window(t_xvar **connect, t_file *infos, int width, int height)
{
	height += infos->win_margin * 2;
	width += infos->win_margin * 2;
	*connect = mlx_init();
	if (*connect == NULL)
		exit (1);
	(*connect)->win_list = mlx_new_window(*connect, width, height, infos->name);
	if ((*connect)->win_list == NULL)
	{
		mlx_destroy_display(*connect);
		free(*connect);
		exit (1);
	}
}

int	close_window(t_xvar **connect)
{
	mlx_loop_end(*connect);
	mlx_destroy_window(*connect, (*connect)->win_list);
	return (0);
}
