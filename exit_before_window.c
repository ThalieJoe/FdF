/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_before_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:24:09 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 14:24:22 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_before_window(t_map *map)
{
	free_plane(map->plane);
	coord_clear(&(map->coord));
	img_clear(map->connect, &map->image);
	mlx_destroy_display(map->connect);
	free(map->connect);
	exit (EXIT_FAILURE);
}
