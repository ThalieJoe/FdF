/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:02:18 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/01 10:03:19 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	adapt_margin_ord(t_map map, t_plane *plane, t_view *view)
{
	int	height;
	int	depth;

	upd_view_vectors(*plane, view);
	height = map.highest * view->z_vect_ord;
	depth = (map.deepest * view->z_vect_ord) * -1;
	if (height > depth)
		plane->margin_ord = depth - 20;
	else
		plane->margin_ord = 20;
}

static void	adapt_margin_abs(t_map map, t_plane *plane, t_view *view)
{
	int	length;
	int	width;

	upd_view_vectors(*plane, view);
	length = map.grid_length * view->x_vect_abs;
	width = map.grid_width * view->y_vect_abs;
	plane->margin_abs = (1920 - (length + width)) / 2;
}

static void	adapt_scale_to_ten(t_plane *plane)
{
	if (plane->x_scale == 0)
		plane->x_scale = 10;
	if (plane->y_scale == 0)
		plane->y_scale = 10;
	if (plane->z_scale == 0)
		plane->z_scale = 10;
}

int	init_plane_height(t_map map, t_plane *plane, t_view view)
{
	int	height;
	int	depth;
	int	margin;

	height = map.highest * view.z_vect_ord;
	depth = (map.deepest * view.z_vect_ord) * -1;
	margin = plane->margin_ord * 2;
	while (height + depth + margin > 1050)
	{
		plane->z_scale = plane->z_scale * 9 / 10;
		if (plane->z_scale == 0)
		{
			adapt_scale_to_ten(plane);
			adapt_margin_ord(map, plane, &view);
			return (1050);
		}
		upd_view_vectors(*plane, &view);
		height = map.highest * view.z_vect_ord;
		depth = (map.deepest * view.z_vect_ord) * -1;
	}
	return (height + depth);
}

int	init_plane_width(t_map map, t_plane *plane, t_view view)
{
	int	length;
	int	width;
	int	margin;

	length = map.grid_length * view.x_vect_abs;
	width = map.grid_width * view.y_vect_abs;
	margin = plane->margin_abs * 2;
	while (length + width + margin > 1920)
	{
		if (length > width)
			plane->x_scale = plane->x_scale * 9 / 10;
		else
			plane->y_scale = plane->y_scale * 9 / 10;
		if (plane->x_scale == 0 || plane->y_scale == 0)
		{
			adapt_scale_to_ten(plane);
			adapt_margin_abs(map, plane, &view);
			return (1920);
		}
		upd_view_vectors(*plane, &view);
		length = map.grid_length * view.x_vect_abs;
		width = map.grid_width * view.y_vect_abs;
	}
	return (length + width);
}
