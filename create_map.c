/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:32:30 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 15:09:48 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	upd_coord_ord(t_coord coord, t_plane plane)
{
	int	ord;
	int	val[3];

	val[0] = coord.x * plane.x->ord;
	val[1] = coord.y * plane.y->ord;
	val[2] = coord.z * plane.z->ord;
	ord = plane.o->ord - val[0] - val[1] - val[2];
	return (ord);
}

static int	upd_coord_abs(t_coord coord, t_plane plane)
{
	int	abs;
	int	val[3];

	val[0] = coord.x * plane.x->abs;
	val[1] = coord.y * plane.y->abs;
	val[2] = coord.z * plane.z->abs;
	abs = plane.o->abs + val[0] + val[1] + val[2];
	return (abs);
}

static void	upd_coord(t_plane *plane, t_coord *coord)
{
	while (coord)
	{
		coord->px->abs = upd_coord_abs(*coord, *plane);
		coord->px->ord = upd_coord_ord(*coord, *plane);
		coord = coord->next;
	}
}

void	create_map(t_img *img, t_plane plane, t_coord *coord)
{
	upd_coord(&plane, coord);
	while (coord)
	{
		draw(img, *coord);
		coord = coord->next;
	}
}
