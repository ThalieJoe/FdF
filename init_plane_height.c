/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane_height.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:57:26 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/11 14:50:35 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	adapt_vertical_margin(t_grid grid, t_plane *plane)
{
	int	height;
	int	depth;

	upd_all_abs(plane);
	upd_all_ord(plane);
	height = (grid.length * plane->x->ord) + (grid.highest * plane->z->ord);
	depth = ((grid.width * plane->y->ord) * -1) + (grid.deepest * plane->z->ord * -1);
	if (height > depth)
		plane->v_marg = depth;
	else
		plane->v_marg = 20;
}

int	init_plane_height(t_grid grid, t_plane *plane)
{
	int	height;
	int	depth;
	int	margin;

	height = (grid.length * plane->x->ord) + (grid.highest * plane->z->ord);
	depth = ((grid.width * plane->y->ord) * -1) + (grid.deepest * plane->z->ord * -1);
	margin = plane->v_marg * 2;
	while (height + depth + margin > 1050)
	{
		plane->z->scale = plane->z->scale * 9 / 10;
		if (plane->z->scale <= plane->x->scale / 2 && plane->z->scale > 10)
			plane->x->scale /= 2;
		if (plane->z->scale <= plane->y->scale / 2 && plane->z->scale > 10)
			plane->y->scale /= 2;
		if (plane->z->scale == 0)
		{
			adapt_scale_to_two(plane);
			adapt_vertical_margin(grid, plane);
			height = (grid.length * plane->x->ord) + (grid.highest * plane->z->ord);
			depth = ((grid.width * plane->y->ord) * -1) + (grid.deepest * plane->z->ord * -1);
			return (500);
		}
		upd_all_abs(plane);
		upd_all_ord(plane);
		height = (grid.length * plane->x->ord) + (grid.highest * plane->z->ord);
		depth = ((grid.width * plane->y->ord) * -1) + (grid.deepest * plane->z->ord * -1);
	}
	return (height + depth);
}
