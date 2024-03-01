/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:49:43 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/01 12:38:50 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	upd_abs_vector(int vect_angle_hor, int scale)
{
	int	abs;

	abs = 0;
	if (vect_angle_hor == 0)
		abs = scale;
	else if (vect_angle_hor <= 90)
		abs =(int)(cos(vect_angle_hor * M_PI / 180) * scale);
	else if (vect_angle_hor < 180)
		abs = (int)((cos((180 - vect_angle_hor) * M_PI / 180) * scale) * (-1));
	else if (vect_angle_hor == 180)
		abs = scale * (-1);
	else if (vect_angle_hor <= 270)
		abs = (int)((cos((vect_angle_hor - 180) * M_PI / 180) * scale) * (-1));
	else
		abs = (int)(cos((360 - vect_angle_hor) * M_PI / 180) * scale);
	return (abs);
}

static void	upd_all_abs(t_plane plane, t_view *view)
{
	ft_printf("---%?33s", "Changing x\n");
	ft_printf("Before vertical_rotation x_vect_abs = %?33d\n", view->x_vect_abs);
	if (view->x_vect_angle_vert != 0 && view->x_vect_angle_vert != 180)
		view->x_vect_abs = upd_abs_vector(view->x_vect_angle_hor, plane.x_scale);
	ft_printf("After vertical_rotation x_vect_abs = %?33d\n", view->x_vect_abs);
	ft_printf("---%?34s", "Changing y\n");
	ft_printf("Before vertical_rotation y_vect_abs = %?34d\n", view->y_vect_abs);
	if (view->y_vect_angle_vert != 0 && view->y_vect_angle_vert != 180)
		view->y_vect_abs = upd_abs_vector(view->y_vect_angle_hor, plane.y_scale);
	ft_printf("After vertical_rotation y_vect_abs = %?34d\n", view->y_vect_abs);
	ft_printf("---%?35s", "Changing z\n");
	ft_printf("Before vertical_rotation z_vect_abs = %?35d\n", view->z_vect_abs);
	if (view->z_vect_angle_vert != 0 && view->z_vect_angle_vert != 180)
		view->z_vect_abs = upd_abs_vector(view->z_vect_angle_hor, plane.z_scale);
	ft_printf("After vertical_rotation z_vect_abs = %?35d\n", view->z_vect_abs);
}

void	vertical_rotation(t_plane plane, t_view *view, int rotation)
{
	while (rotation < 0)
		rotation += 360;
	while (rotation >= 360)
		rotation -= 360;
	ft_printf("Before vertical_rotation, x_vect_angle_vert = %?33d\n", view->x_vect_angle_vert);
	if (view->x_vect_angle_vert != 0 && view->x_vect_angle_vert != 180)
		view->x_vect_angle_hor = (view->x_vect_angle_hor + rotation) % 360;
	ft_printf("After vertical_rotation, x_vect_angle_vert = %?33d\n", view->x_vect_angle_vert);
	ft_printf("After vertical_rotation, x_vect_angle_hor = %?33d\n", view->x_vect_angle_hor);
	ft_printf("Before vertical_rotation, y_vect_angle_vert = %?34d\n", view->y_vect_angle_vert);
	if (view->y_vect_angle_vert != 0 && view->y_vect_angle_vert != 180)
		view->y_vect_angle_hor = (view->y_vect_angle_hor + rotation) % 360;
	ft_printf("After vertical_rotation, y_vect_angle_vert = %?34d\n", view->y_vect_angle_vert);
	ft_printf("After vertical_rotation, y_vect_angle_hor = %?34d\n", view->y_vect_angle_hor);
	ft_printf("Before vertical_rotation, z_vect_angle_vert = %?35d\n", view->z_vect_angle_vert);
	if (view->z_vect_angle_vert != 0 && view->z_vect_angle_vert != 180)
		view->z_vect_angle_hor = (view->z_vect_angle_hor + rotation) % 360;
	ft_printf("After vertical_rotation, z_vect_angle_vert = %?35d\n", view->z_vect_angle_vert);
	ft_printf("After vertical_rotation, z_vect_angle_hor = %?35d\n", view->z_vect_angle_hor);
	upd_all_abs(plane, view);
}
