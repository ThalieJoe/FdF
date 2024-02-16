/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_close_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:35:29 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/15 16:13:00 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	open_window(t_xvar **connect)
{
	*connect = mlx_init();
	if (*connect == NULL)
		exit (1);
	(*connect)->win_list = mlx_new_window(*connect, 990, 540, "sarah's window");
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
