/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:31:01 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/23 16:04:48 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_scales(t_file *infos)
{
	int		width;
	int		height;

	infos->scaled_elems = infos->scales[0] * infos->elems;
	infos->scaled_lines = infos->scales[1] * infos->lines;
	width = (int)(sqrt((pow(infos->scaled_elems, 2) + pow(infos->scaled_lines, 2))));
	height = infos->size * infos->scales[2];
	ft_printf("in get scales, height = %d\n", height);
	ft_printf("in get scales, height = %d\n", height);
	while (height > 1080)
	{
		infos->scales[2] = infos->scales[2] * 9 / 10;
		height = infos->size * infos->scales[2];
	}
	while (width > 1990)
	{
		if (fmax(infos->scaled_elems, infos->scaled_lines == infos->scaled_elems))
			infos->scales[0] = infos->scales[0] * 9 /10;
		else
			infos->scales[1] = infos->scales[1] * 9 /10;
	}
}

t_img	*init_image(t_xvar **connect, t_file *infos, t_plane *plane)
{
	t_img	*img;
	int		width;
	int		height;

	get_scales(infos);
	create_plane(plane, *infos);
	width = plane->x_abs * infos->elems + plane->y_abs * infos->lines;
	height = infos->size * infos->scales[2];
	open_window(connect, infos, width, height);
	img = mlx_new_image(*connect, width, height);
	ft_printf("----- width = %?36d, height = %?36d\n", width, height);
	if (!img)
	{
		close_window(connect);
		mlx_destroy_display(*connect);
		free(*connect);
		exit (1);
	}
	img->data = mlx_get_data_addr(img, &img->bpp, &img->size_line, &img->image->byte_order);
	mlx_hook((*connect)->win_list, 17, 1L << 17, &close_window, connect);
	mlx_key_hook((*connect)->win_list, &handle_key_input, connect);
	return (img);
}
