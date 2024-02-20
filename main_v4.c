/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_v4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:43:08 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/19 16:49:43 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_xvar	*connect;
	t_img	*img;
	t_file	infos;

	if (argc != 2)
		return (0);
	check_file_ext(argv[1]);
	parse_file(argv[1], &infos);
	img = init_image(&connect);
	create_image(&connect, &img, argv[1]);
	mlx_put_image_to_window(connect, connect->win_list, img, 50, 50);
	mlx_loop(connect);
	clean_and_exit(&connect, &img);
	return (0);
}
