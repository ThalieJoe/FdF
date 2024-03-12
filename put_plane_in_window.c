/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_plane_in_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:16:46 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/12 17:22:38 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_coord_in_win(t_vect *vect, t_px origin)
{
	vect->in_win->abs = origin.abs + vect->abs;
	vect->in_win->ord = origin.ord - vect->ord;
}

static void	init_all_vect_coord_in_win(t_plane *plane)
{
	init_coord_in_win(plane->x, (*plane->o));
	init_coord_in_win(plane->y, (*plane->o));
	init_coord_in_win(plane->z, (*plane->o));
}

static void	find_origins_in_win(t_grid grid, t_plane plane, t_px *origin)
{
	origin->abs = plane.h_marg;
	origin->ord = (grid.length * plane.x->ord) + (grid.highest * plane.z->ord) + plane.v_marg;
}

void	put_plane_in_window(t_xvar *connect, t_grid grid, t_plane *plane)
{
	find_origins_in_win(grid, *plane, plane->o);
	if (plane->v_marg < 0 && grid.highest > grid.deepest * -1)
		plane->o->ord = 1050 - 50;
	init_all_vect_coord_in_win(plane);
	show_plane(connect, *plane, *(plane->o));
}
