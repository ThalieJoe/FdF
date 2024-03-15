/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:43:08 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/15 16:10:08 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "time.h"

int	main(int argc, char **argv)
{
	t_xvar	*connect;
	t_grid	grid;
	t_coord	*coord;
	t_plane	plane;
	clock_t	start, end;
	double	cpu_time_used;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf <argument>\n", 2);
		exit (EXIT_FAILURE);
	}
	connect = NULL;
	coord = NULL;
	start = clock();
	parse_grid(argv[1], &grid, &coord);
	printf("Grid parsed...\n");
	init_plane(grid, &plane, &coord);
	printf("Plane initiated...\n");
	open_window(&connect, grid, plane, &coord);
	printf("Window opened...\n");
	put_plane_in_window(connect, grid, &plane);
	printf("Plane put in window...\n");
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken to open window: %f seconds\n", cpu_time_used);
	start = clock();
	create_map(connect, plane, coord);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Map created...\n");
	printf("Time taken to create map: %f seconds\n", cpu_time_used);
	mlx_loop(connect);
	clean_and_exit(connect, &plane, &coord, 0);
	return (0);
}
