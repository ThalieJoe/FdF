/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane_height.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:57:26 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/15 16:09:19 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	upd_plane_width(t_grid grid, t_plane *plane)
{
	int	length;
	int	width;

	length = (grid.length - 1) * plane->x->abs;
	width = (grid.width - 1) * plane->y->abs;
	if (length + width > 1920)
		return (1920);
	return (length + width);
}

/*
Keeps the scales coherent
*/
static void	standardize_scales(t_grid grid, t_plane *plane)
{
	bool	mod_sc;

	mod_sc = false;
	if (plane->z->scale <= plane->x->scale / 2 && plane->z->scale > 10)
	{
		plane->x->scale /= 2;
		mod_sc = true;
	}
	if (plane->z->scale <= plane->y->scale / 2 && plane->z->scale > 10)
	{
		plane->y->scale /= 2;
		mod_sc = true;
	}
	if (plane->x->scale < 5 || plane->y->scale < 5)
		plane->h_rot = 45;
	upd_all_abs(plane);
	upd_all_ord(plane);
	if (mod_sc)
		plane->width = upd_plane_width(grid, plane);
}

static int	upd_plane_height(t_grid grid, t_plane *plane)
{
	int	height;
	int	depth;

	height = get_height(grid, *plane);
	depth = get_depth(grid, *plane);
	while (height + depth > 1050)
	{
		plane->x->scale = plane->x->scale * 9 / 10;
		plane->y->scale = plane->y->scale * 9 / 10;
		if (plane->x->scale < 3 || plane->y->scale < 3)
		{
			adapt_scale_to_three(plane);
			return (1050);
		}
		upd_all_abs(plane);
		upd_all_ord(plane);
		height = get_height(grid, *plane);
		depth = get_depth(grid, *plane);
	}
	return (height + depth);
}

/*
Calculate height of the plane and adapt scales if needed
*/
int	init_plane_height(t_grid grid, t_plane *plane)
{
	int	height;
	int	depth;

	height = get_height(grid, *plane);
	depth = get_depth(grid, *plane);
	while (height + depth > 1050)
	{
		plane->z->scale = plane->z->scale * 9 / 10;
		if (plane->z->scale < 3)
		{
			adapt_scale_to_three(plane);
			plane->height = upd_plane_height(grid, plane);
			plane->width = upd_plane_width(grid, plane);
			return (plane->height);
		}
		standardize_scales(grid, plane);
		height = get_height(grid, *plane);
		depth = get_depth(grid, *plane);
	}
	return (height + depth);
}
