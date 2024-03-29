/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:43:08 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 16:00:02 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./fdf <argument>", 2);
		exit (EXIT_FAILURE);
	}
	init_map(&map);
	parse_grid(argv[1], &map);
	map.plane = init_plane(map.grid, &(map.coord));
	create_image(&map);
	put_plane_in_image(map.grid, map.plane);
	create_map(map.image->img, *map.plane, map.coord);
	open_window(&map);
	clean_all(&map);
	return (0);
}
