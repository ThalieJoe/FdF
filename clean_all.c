/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:37:09 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 15:59:54 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_all(t_map *map)
{
	free_plane(map->plane);
	coord_clear(&(map->coord));
	img_clear(map->connect, &map->image);
	mlx_destroy_window(map->connect, map->connect->win_list);
	mlx_destroy_display(map->connect);
	free(map->connect);
}
