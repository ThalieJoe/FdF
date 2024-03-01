/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_my_axis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:24:23 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/01 17:10:46 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_my_axis_x(t_view *view, int hor_rot, int vert_rot)
{
	if (hor_rot % 180 == 90 && vert_rot % 180 == 0)
		view->x_vect_vert_ax = true;
	else
		view->x_vect_vert_ax = false;
	if (hor_rot % 180 == 0 && vert_rot % 180 == 90)
		view->x_vect_hor_ax = true;
	else
		view->x_vect_hor_ax = false;
}

void	check_my_axis_y(t_view *view, int hor_rot, int vert_rot)
{
	if (hor_rot % 180 == 90 && vert_rot % 180 == 90)
		view->y_vect_vert_ax = true;
	else
		view->y_vect_vert_ax = false;
	if (hor_rot % 180 == 0 && vert_rot % 180 == 0)
		view->y_vect_hor_ax = true;
	else
		view->y_vect_hor_ax = false;
}

void	check_my_axis_z(t_view *view, int hor_rot, int vert_rot)
{
	if (hor_rot % 180 == 0 && vert_rot % 180 == 0)
		view->z_vect_vert_ax = true;
	else
		view->z_vect_vert_ax = false;
	if (hor_rot % 180 == 90 && vert_rot % 180 == 90)
		view->z_vect_hor_ax = true;
	else
		view->z_vect_hor_ax = false;
}
