/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upd_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:14:50 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/29 13:15:34 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	upd_view_angle(t_view *view, int x, int y, int z)
// {
// 	view->x_rotation = x;
// 	view->y_rotation = y;
// 	view->z_rotation = z;
// }

void	upd_view_vectors(t_plane plane, t_view *view)
{
	view->x_vect_abs = plane.x_scale * 0;
	view->x_vect_ord = plane.x_scale * 0;
	view->y_vect_abs = plane.y_scale * 1;
	view->y_vect_ord = plane.y_scale * 0;
	view->z_vect_abs = plane.z_scale * 0;
	view->z_vect_ord = plane.z_scale * 1;
}
