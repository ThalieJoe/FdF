/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:08:51 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/06 15:09:48 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// x yellow | y turquoise | z pink
void	show_plane(t_xvar *connect, t_plane plane, t_view *view)
{
	mlx_pixel_put(connect, connect->win_list, plane.xorigin_in_win, plane.yorigin_in_win, 0xFFFF00);
	if (view->x_vect_abs >= 0)
		draw_vector_pos(connect, plane, plane.x_abs_in_win, plane.x_ord_in_win, 0xAAAA00);
	else
		draw_vector_neg(connect, plane, plane.x_abs_in_win, plane.x_ord_in_win, 0xAAAA00);
	if (view->y_vect_abs >= 0)
		draw_vector_pos(connect, plane, plane.y_abs_in_win, plane.y_ord_in_win, 0x00AAAA);
	else
		draw_vector_neg(connect, plane, plane.y_abs_in_win, plane.y_ord_in_win, 0x00AAAA);
	if (view->z_vect_abs >= 0)
		draw_vector_pos(connect, plane, plane.z_abs_in_win, plane.z_ord_in_win, 0xAA00AA);
	else
		draw_vector_neg(connect, plane, plane.z_abs_in_win, plane.z_ord_in_win, 0xAA00AA);
}
