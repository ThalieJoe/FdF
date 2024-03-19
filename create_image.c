/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:37:10 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 14:23:49 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_image_width(t_grid grid, t_plane plane)
{
	int	width;

	if (grid.length == 1 && grid.width == 1)
		width = 100;
	else if (plane.h_marg > 0)
		width = plane.width + (plane.h_marg * 2);
	else
		width = plane.width;
	return (width);
}

static int	get_image_height(t_grid grid, t_plane plane)
{
	int	height;

	if (grid.length == 1 && grid.width == 1)
		height = 50;
	else if (plane.v_marg > 0)
		height = plane.height + (plane.v_marg * 2);
	else
		height = plane.height;
	return (height);
}

void	create_image(t_map *map)
{
	int		width;
	int		height;
	t_img	*img;
	t_image	*new;

	map->connect = mlx_init();
	if (map->connect == NULL)
	{
		free_plane(map->plane);
		coord_clear(&(map->coord));
		exit (EXIT_FAILURE);
	}
	width = get_image_width(map->grid, *(map->plane));
	height = get_image_height(map->grid, *(map->plane));
	img = (t_img *)mlx_new_image(map->connect, width, height);
	if (img == NULL)
		exit_before_window(map);
	new = (t_image *)ft_lstnew(img);
	if (new == NULL)
		exit_before_window(map);
	map->image = new;
}
