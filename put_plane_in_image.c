/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_plane_in_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:16:46 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 15:07:12 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	find_coord_in_win(t_vect *vect, t_px origin)
{
	vect->in_win->abs = origin.abs + vect->abs;
	vect->in_win->ord = origin.ord - vect->ord;
}

static void	find_vectors_coordinates(t_plane *plane)
{
	find_coord_in_win(plane->x, *(plane->o));
	find_coord_in_win(plane->y, *(plane->o));
	find_coord_in_win(plane->z, *(plane->o));
}

static void	find_origin_in_win(t_grid grid, t_plane plane, t_px *origin)
{
	int	rot_height;
	int	map_height;

	origin->abs = plane.h_marg;
	rot_height = grid.length * ft_valabs(plane.x->ord);
	map_height = grid.highest * plane.z->ord;
	origin->ord = rot_height + map_height + plane.v_marg;
}

void	put_plane_in_image(t_grid grid, t_plane *plane)
{
	find_origin_in_win(grid, *plane, plane->o);
	find_vectors_coordinates(plane);
}
