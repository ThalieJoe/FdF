/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane_height.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:57:26 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/12 16:53:31 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Keeps the scales coherent
*/
static void	standardize_scales(t_plane *plane)
{
	if (plane->z->scale <= plane->x->scale / 2 && plane->z->scale > 10)
		plane->x->scale /= 2;
	if (plane->z->scale <= plane->y->scale / 2 && plane->z->scale > 10)
		plane->y->scale /= 2;
}

/*
Get the newest ord of the highest scaled coordinate
*/
static int	get_height(t_grid grid, t_plane plane)
{
	int	height;
	int	scaled_highest;

	scaled_highest = grid.highest * plane.z->ord;
	height = (grid.length * plane.x->ord) + scaled_highest;
	return (height);
}

/*
Get the newest ord of the deepest scaled coordinate
*/
static int	get_depth(t_grid grid, t_plane plane)
{
	int	depth;
	int	scaled_deepest;

	scaled_deepest = grid.deepest * plane.z->ord;
	depth = (grid.width * plane.y->ord) + scaled_deepest;
	ft_printf("In get_depth, depth = %d\n (pos depth is returned!)\n", depth);
	return (depth * (-1));
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
		standardize_scales(plane);
		if (plane->z->scale == 0)
		{
			adapt_scale_to_two(plane);
			return (1050);
		}
		upd_all_abs(plane);
		upd_all_ord(plane);
		height = get_height(grid, *plane);
		depth = get_depth(grid, *plane);
	}
	return (height + depth);
}
