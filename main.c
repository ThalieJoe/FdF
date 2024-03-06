/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:43:08 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/06 16:21:26 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_xvar	*connect;
	// t_img	*img;
	t_map		map;
	t_plane		plane;
	// int		margin;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf <argument>\n", 2);
		exit (EXIT_FAILURE);
	}
	connect = NULL;
	check_map(argv[1]);
	parse_map(argv[1], &map);
	init_plane(map, &plane);
	open_window(&connect, map, plane);
	put_plane_in_window(connect, map, &plane);
	// img = init_image(&connect, &infos ,&plane);
	create_map(connect, map, plane);
	// margin = infos.win_margin;
	// mlx_put_image_to_window(connect, connect->win_list, img, margin, margin);
	mlx_loop(connect);
	clean_and_exit(connect, &plane, 0);
	// free(map.plane);
	return (0);
}
