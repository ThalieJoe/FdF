/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:49:19 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 15:29:33 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	right_translation(t_map *map)
{
	int		width;
	int		height;
	t_xvar	*c;

	width = map->image->img->width;
	height = map->image->img->height;
	c = map->connect;
	if (map->plane->o->abs < map->image->img->width)
		map->plane->o->abs += 10;
	add_new_image(map, width, height);
	create_map(map->image->img, *(map->plane), map->coord);
	mlx_put_image_to_window(c, c->win_list, map->image->img, 0, 0);
}

void	left_translation(t_map *map)
{
	int		width;
	int		height;
	t_xvar	*c;

	width = map->image->img->width;
	height = map->image->img->height;
	c = map->connect;
	if (map->plane->o->abs > (map->image->img->width * -1))
		map->plane->o->abs -= 10;
	add_new_image(map, width, height);
	create_map(map->image->img, *(map->plane), map->coord);
	mlx_put_image_to_window(c, c->win_list, map->image->img, 0, 0);
}

void	up_translation(t_map *map)
{
	int		width;
	int		height;
	t_xvar	*c;

	width = map->image->img->width;
	height = map->image->img->height;
	c = map->connect;
	if (map->plane->o->ord > (map->grid.width * map->plane->y->ord))
		map->plane->o->ord -= 10;
	add_new_image(map, width, height);
	create_map(map->image->img, *(map->plane), map->coord);
	mlx_put_image_to_window(c, c->win_list, map->image->img, 0, 0);
}

void	down_translation(t_map *map)
{
	int		width;
	int		height;
	t_xvar	*c;

	width = map->image->img->width;
	height = map->image->img->height;
	c = map->connect;
	if (map->plane->o->ord < map->image->img->height * 2)
		map->plane->o->ord += 10;
	add_new_image(map, width, height);
	create_map(map->image->img, *(map->plane), map->coord);
	mlx_put_image_to_window(c, c->win_list, map->image->img, 0, 0);
}
