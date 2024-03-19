/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:42:32 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 15:31:48 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	down_rotation(t_map *map)
{
	int		width;
	int		height;
	t_xvar	*c;

	width = map->image->img->width;
	height = map->image->img->height;
	c = map->connect;
	if (map->plane->h_rot < 90)
		map->plane->h_rot += 5;
	add_new_image(map, width, height);
	upd_all_ord(map->plane);
	create_map(map->image->img, *(map->plane), map->coord);
	mlx_put_image_to_window(c, c->win_list, map->image->img, 0, 0);
}

void	up_rotation(t_map *map)
{
	int		width;
	int		height;
	t_xvar	*c;

	width = map->image->img->width;
	height = map->image->img->height;
	c = map->connect;
	if (map->plane->h_rot > 0)
		map->plane->h_rot -= 5;
	add_new_image(map, width, height);
	upd_all_ord(map->plane);
	create_map(map->image->img, *(map->plane), map->coord);
	mlx_put_image_to_window(c, c->win_list, map->image->img, 0, 0);
}
