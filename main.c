/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:43:08 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/11 17:11:53 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_xvar	*connect;
	t_grid	grid;
	t_plane	plane;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf <argument>\n", 2);
		exit (EXIT_FAILURE);
	}
	connect = NULL;
	parse_grid(argv[1], &grid);
	init_plane(grid, &plane);
	open_window(&connect, grid, plane);
	put_plane_in_window(connect, grid, &plane);
	create_map(connect, grid, plane);
	mlx_loop(connect);
	free_plane(&plane);
	clean_and_exit(connect, 0);
	return (0);
}
