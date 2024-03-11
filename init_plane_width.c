/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:02:18 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/11 13:15:56 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	adapt_horizontal_margin(t_grid grid, t_plane *plane)
{
	int	length;
	int	width;

	upd_all_abs(plane);
	upd_all_ord(plane);
	length = grid.length * plane->x->abs;
	width = grid.width * plane->y->abs;
	plane->h_marg = (1920 - (length + width)) / 2;
}

int	init_plane_width(t_grid grid, t_plane *plane)
{
	int	length;
	int	width;
	int	margin;

	length = grid.length * plane->x->abs;
	width = grid.width * plane->y->abs;
	margin = plane->h_marg * 2;
	while (length + width + margin > 1920)
	{
		if (length > width)
		{
			plane->x->scale = plane->x->scale * 9 / 10;
			if (plane->x->scale <= plane->y->scale / 2)
				plane->y->scale /= 2;
		}
		else
		{
			plane->y->scale = plane->y->scale * 9 / 10;
			if (plane->y->scale <= plane->x->scale / 2)
				plane->x->scale /= 2;
		}
		if (plane->x->scale <= plane->z->scale / 2 || plane->y->scale <= plane->z->scale / 2)
		{
			plane->z->scale /= 2;
			plane->height = init_plane_height(grid, plane);
		}
		if (plane->x->scale == 0 || plane->y->scale == 0)
		{
			adapt_scale_to_two(plane);
			adapt_horizontal_margin(grid, plane);
			return (1920);
		}
		upd_all_abs(plane);
		upd_all_ord(plane);
		length = grid.length * plane->x->abs;
		width = grid.width * plane->y->abs;
	}
	return (length + width);
}
