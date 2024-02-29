/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:08:51 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/29 16:39:27 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// x yellow | y turquoise | z pink

void	show_plane(t_xvar *connect, t_plane plane, t_view *view)
{
	mlx_pixel_put(connect, connect->win_list, plane.xorigin_in_win, plane.yorigin_in_win, 0xFFFF00);
	if (view->x_vect_abs >= plane.xorigin_in_win)
		draw_vector_pos(connect, plane, view->x_vect_abs, view->x_vect_ord, 0xAAAA00);
	else
		draw_vector_neg(connect, plane, view->x_vect_abs, view->x_vect_ord, 0xAAAA00);
	if (view->y_vect_abs >= plane.xorigin_in_win)
		draw_vector_pos(connect, plane, view->y_vect_abs, view->y_vect_ord, 0x00AAAA);
	else
		draw_vector_neg(connect, plane, view->y_vect_abs, view->y_vect_ord, 0x00AAAA);
	if (view->z_vect_abs >= plane.xorigin_in_win)
		draw_vector_pos(connect, plane, view->z_vect_abs, view->z_vect_ord, 0xAA00AA);
	else
		draw_vector_neg(connect, plane, view->z_vect_abs, view->z_vect_ord, 0xAA00AA);
}
