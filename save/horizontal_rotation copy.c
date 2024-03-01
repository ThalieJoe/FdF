/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:54:08 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/01 13:17:35 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	upd_ord_vector(int angle_vert, int scale)
{
	int	ord;

	ord = 0;
	if (angle_vert == 0)
		ord = scale;
	else if (angle_vert <= 90)
		ord = (int)((cos(angle_vert * M_PI / 180)) * scale);
	else if (angle_vert < 180)
		ord = (int)(((cos((180 - angle_vert) * M_PI / 180)) * scale) * (-1));
	else if (angle_vert == 180)
		ord = -scale;
	else if (angle_vert < 270)
		ord = (int)(((cos((angle_vert - 180) * M_PI / 180)) * scale) * (-1));
	else
		ord = (int)((cos((360 - angle_vert) * M_PI / 180)) * scale);
	return (ord);
}

static void	upd_all_ord(t_plane plane, t_view *view)
{
	ft_printf("---%?33s", "Changing x\n");
	ft_printf("Before horizontal_rotation, x_vect_ord = %?33d\n", view->x_vect_ord);
	if (view->x_vect_angle_hor != 0 && view->x_vect_angle_hor != 180)
		view->x_vect_ord = upd_ord_vector(view->x_vect_angle_vert, plane.x_scale);
	ft_printf("After horizontal_rotation, x_vect_ord = %?33d\n", view->x_vect_ord);
	ft_printf("---%?34s", "Changing y\n");
	ft_printf("Before horizontal_rotation, y_vect_ord = %?34d\n", view->y_vect_ord);
	if (view->y_vect_angle_hor != 0 && view->y_vect_angle_hor != 180)
		view->y_vect_ord = upd_ord_vector(view->y_vect_angle_vert, plane.y_scale);
	ft_printf("After horizontal_rotation, y_vect_ord = %?34d\n", view->y_vect_ord);
	ft_printf("---%?35s", "Changing z\n");
	ft_printf("Before horizontal_rotation, z_vect_ord = %?35d\n", view->z_vect_ord);
	if (view->z_vect_angle_hor != 0 && view->z_vect_angle_hor != 180)
		view->z_vect_ord = upd_ord_vector(view->z_vect_angle_vert, plane.z_scale);
	ft_printf("After horizontal_rotation, z_vect_ord = %?35d\n", view->z_vect_ord);
}

void	horizontal_rotation(t_plane plane, t_view *view, int rotation)
{
	while (rotation < 0)
		rotation += 360;
	while (rotation > 360)
		rotation -= 360;
	ft_printf("Before horizontal_rotation, x_vect_angle_hor = %?33d\n", view->x_vect_angle_hor);
	if (view->x_vect_angle_hor != 0 && view->x_vect_angle_hor != 180)
		view->x_vect_angle_vert = (view->x_vect_angle_vert + rotation) % 360;
	ft_printf("After horizontal_rotation, x_vect_angle_hor = %?33d\n", view->x_vect_angle_hor);
	ft_printf("After horizontal_rotation, x_vect_angle_vert = %?33d\n", view->x_vect_angle_vert);
	ft_printf("Before horizontal_rotation, y_vect_angle_hor = %?34d\n", view->y_vect_angle_hor);
	if (view->y_vect_angle_hor != 0 && view->y_vect_angle_hor != 180)
		view->y_vect_angle_vert = (view->y_vect_angle_vert + rotation) % 360;
	ft_printf("After horizontal_rotation, y_vect_angle_hor = %?34d\n", view->y_vect_angle_hor);
	ft_printf("After horizontal_rotation, y_vect_angle_vert = %?34d\n", view->y_vect_angle_vert);
	ft_printf("Before horizontal_rotation, z_vect_angle_hor = %?35d\n", view->z_vect_angle_hor);
	if (view->z_vect_angle_hor != 0 && view->z_vect_angle_hor != 180)
		view->z_vect_angle_vert = (view->z_vect_angle_vert + rotation) % 360;
	ft_printf("After horizontal_rotation, z_vect_angle_hor = %?35d\n", view->z_vect_angle_hor);
	ft_printf("After horizontal_rotation, z_vect_angle_vert = %?35d\n", view->z_vect_angle_vert);
	upd_all_ord(plane, view);
}
