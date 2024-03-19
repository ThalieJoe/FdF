/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:14:00 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 15:58:58 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_in(t_map *map)
{
	int		width;
	int		height;
	t_xvar	*c;

	width = map->image->img->width;
	height = map->image->img->height;
	c = map->connect;
	map->plane->x->scale++;
	map->plane->y->scale++;
	map->plane->z->scale++;
	add_new_image(map, width, height);
	upd_all_abs(map->plane);
	upd_all_ord(map->plane);
	create_map(map->image->img, *(map->plane), map->coord);
	mlx_put_image_to_window(c, c->win_list, map->image->img, 0, 0);
}

void	zoom_out(t_map *map)
{
	int		width;
	int		height;
	t_xvar	*c;

	width = map->image->img->width;
	height = map->image->img->height;
	c = map->connect;
	map->plane->x->scale--;
	map->plane->y->scale--;
	map->plane->z->scale--;
	add_new_image(map, width, height);
	upd_all_abs(map->plane);
	upd_all_ord(map->plane);
	create_map(map->image->img, *(map->plane), map->coord);
	mlx_put_image_to_window(c, c->win_list, map->image->img, 0, 0);
}
