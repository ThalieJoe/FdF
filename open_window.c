/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:35:29 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 15:17:00 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	open_window(t_map *map)
{
	int		width;
	int		height;
	t_xvar	*c;

	width = map->image->img->width;
	height = map->image->img->height;
	c = map->connect;
	c->win_list = mlx_new_window(c, width, height, map->grid.name);
	if (c->win_list == NULL)
		exit_before_window(map);
	mlx_put_image_to_window(c, c->win_list, map->image->img, 0, 0);
	mlx_key_hook(c->win_list, &handle_key_input, map);
	mlx_hook(c->win_list, 17, 1L << 17, &mlx_loop_end, c);
	mlx_loop(c);
}
