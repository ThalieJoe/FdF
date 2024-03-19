/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:02:18 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 14:09:29 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Keeps the scales coherent
*/
static void	standardize_scales(t_grid grid, t_plane *plane)
{
	(void)grid;
	if (plane->x->scale <= plane->y->scale / 2)
		plane->y->scale /= 2;
	if (plane->y->scale <= plane->x->scale / 2)
		plane->x->scale /= 2;
	if (plane->x->scale <= plane->z->scale / 2
		|| plane->y->scale <= plane->z->scale / 2)
		plane->z->scale /= 2;
	if (plane->x->scale < 5 || plane->y->scale < 5)
		plane->h_rot = 45;
}

/*
Calculate width of the plane and adapt scales if needed
*/
int	init_plane_width(t_grid grid, t_plane *plane)
{
	int	length;
	int	width;

	length = (grid.length - 1) * plane->x->abs;
	width = (grid.width - 1) * plane->y->abs;
	while (length + width > 1920)
	{
		if (length >= width)
			plane->x->scale = plane->x->scale * 9 / 10;
		if (length <= width)
			plane->y->scale = plane->y->scale * 9 / 10;
		if (plane->x->scale < 3 || plane->y->scale < 3)
		{
			adapt_scale_to_three(plane);
			return (1920);
		}
		standardize_scales(grid, plane);
		upd_all_abs(plane);
		upd_all_ord(plane);
		length = (grid.length - 1) * plane->x->abs;
		width = (grid.width - 1) * plane->y->abs;
	}
	return (length + width);
}
