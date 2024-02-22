/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_v4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:43:08 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/21 16:29:36 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_xvar	*connect;
	t_img	*img;
	t_file	infos;
	t_plan	plane;
	int		margin;

	if (argc != 2)
		return (0);
	parse_file(argv[1], &infos);
	img = init_image(&connect, &infos ,&plane);
	create_image(&connect, &img, argv[1], &plane);
	margin = infos.win_margin;
	mlx_put_image_to_window(connect, connect->win_list, img, margin, margin);
	mlx_loop(connect);
	clean_and_exit(&connect, &img);
	return (0);
}
