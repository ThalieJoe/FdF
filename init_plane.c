/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:58:57 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/29 17:29:41 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	adapt_margin_ord(t_map map, t_plane *plane, t_view *view)
{
	int	height;
	int	depth;

	upd_view_vectors(*plane, view);
	height = map.highest * view->z_vect_ord;
	depth = (map.deepest * view->z_vect_ord) * -1;
	if (height > depth)
		plane->margin_ord = depth - 20;
	else
		plane->margin_ord = 20;
}

static void	adapt_margin_abs(t_map map, t_plane *plane, t_view *view)
{
	int	length;
	int	width;

	upd_view_vectors(*plane, view);
	length = map.grid_length * view->x_vect_abs;
	width = map.grid_width * view->y_vect_abs;
	plane->margin_abs = (1920 - (length + width)) / 2;
}

static void	adapt_scale_to_ten(t_plane *plane)
{
	if (plane->x_scale == 0)
		plane->x_scale = 10;
	if (plane->y_scale == 0)
		plane->y_scale = 10;
	if (plane->z_scale == 0)
		plane->z_scale = 10;
}

static int	init_plane_height(t_map map, t_plane *plane, t_view view)
{
	int	height;
	int	depth;
	int	margin;

	height = map.highest * view.z_vect_ord;
	depth = (map.deepest * view.z_vect_ord) * -1;
	margin = plane->margin_ord * 2;
	while (height + depth + margin > 1050)
	{
		plane->z_scale = plane->z_scale * 9 / 10;
		if (plane->z_scale == 0)
		{
			adapt_scale_to_ten(plane);
			adapt_margin_ord(map, plane, &view);
			return (1050);
		}
		upd_view_vectors(*plane, &view);
		height = map.highest * view.z_vect_ord;
		depth = (map.deepest * view.z_vect_ord) * -1;
	}
	return (height + depth);
}

static int	init_plane_width(t_map map, t_plane *plane, t_view view)
{
	int	length;
	int	width;
	int	margin;

	length = map.grid_length * view.x_vect_abs;
	width = map.grid_width * view.y_vect_abs;
	margin = plane->margin_abs * 2;
	while (length + width + margin > 1920)
	{
		if (length > width)
			plane->x_scale = plane->x_scale * 9 / 10;
		else
			plane->y_scale = plane->y_scale * 9 / 10;
		if (plane->x_scale == 0 || plane->y_scale == 0)
		{
			adapt_scale_to_ten(plane);
			adapt_margin_abs(map, plane, &view);
			return (1920);
		}
		upd_view_vectors(*plane, &view);
		length = map.grid_length * view.x_vect_abs;
		width = map.grid_width * view.y_vect_abs;
	}
	return (length + width);
}

static void	init_view_1(t_plane plane, t_view *view)
{
	view->hor_rotation = 0;
	view->vert_rotation = 0;
	view->x_vect_abs = 0;
	view->x_vect_ord = 0;
	view->y_vect_abs = plane.y_scale;
	view->y_vect_ord = 0;
	view->z_vect_abs = 0;
	view->z_vect_ord = plane.z_scale;
	view->x_vect_angle_hor = 270;
	view->x_vect_angle_vert = 270;
	view->y_vect_angle_hor = 0;
	view->y_vect_angle_vert = 90;
	view->z_vect_angle_hor = 90;
	view->z_vect_angle_vert = 0;
}

int	upd_abs_vector(int vect_angle_vert, int vect_angle_hor, int scale)
{
	int	vect_abs;

	vect_abs = 0;
	if (vect_angle_vert != 0 && vect_angle_vert != 180)
	{
		ft_printf("1- in upd_abs_vector vect_angle_hor = %d\n", vect_angle_hor);
		if (vect_angle_hor > 90 && vect_angle_hor < 270)
		{
			if (vect_angle_hor == 180)
				vect_abs = scale * (-1);
			else if (vect_angle_hor < 180)
				vect_abs = (int)((cos((180 - vect_angle_hor) * M_PI / 180) * scale) * (-1));
			else
				vect_abs = (int)((cos((vect_angle_hor - 180) * M_PI / 180) * scale) * (-1));
		}
		else
		{
			if (vect_angle_hor == 0)
				vect_abs = scale;
			else if (vect_angle_hor <= 90)
				vect_abs = (int)(cos(vect_angle_hor * M_PI / 180) * scale);
			else
				vect_abs = (int)(cos((360 - vect_angle_hor) * M_PI / 180) * scale);
		}
		ft_printf("2- in upd_abs_vector vect_abs = %d\n", vect_abs);

	}
	return (vect_abs);
}

void	upd_all_abs(t_plane plane, t_view *view)
{
	ft_printf("---%?32s", "Changing x\n");
	view->x_vect_abs = upd_abs_vector(view->x_vect_angle_vert, view->x_vect_angle_hor, plane.x_scale);
	ft_printf("---%?33s", "Changing y\n");
	view->y_vect_abs = upd_abs_vector(view->y_vect_angle_vert, view->y_vect_angle_hor, plane.y_scale);
	ft_printf("---%?34s", "Changing z\n");
	view->z_vect_abs = upd_abs_vector(view->z_vect_angle_vert, view->z_vect_angle_hor, plane.z_scale);
}

void	rotation_vert(t_plane plane, t_view *view, int rotation)
{
	// ft_printf("ENTERING rot_vert, vert_rotation = %d\n", view->vert_rotation);
	while (rotation < 0)
		rotation += 360;
	while (rotation > 360)
		rotation -= 360;
	if (view->x_vect_angle_vert != 0 && view->x_vect_angle_vert != 180)
	{
		ft_printf("In rotation vert, view->x_vect_angle_hor = %d\n", view->x_vect_angle_hor);
		view->x_vect_angle_hor = (view->x_vect_angle_hor + rotation) % 360;
		ft_printf("In rotation vert, view->x_vect_angle_hor = %d\n", view->x_vect_angle_hor);

	}
	if (view->y_vect_angle_vert != 0 && view->y_vect_angle_vert != 180)
	{
		ft_printf("In rotation vert, view->y_vect_angle_hor = %d\n", view->y_vect_angle_hor);
		view->y_vect_angle_hor = (view->y_vect_angle_hor + rotation) % 360;
		ft_printf("In rotation vert, view->y_vect_angle_hor = %d\n", view->y_vect_angle_hor);
	}
	if (view->z_vect_angle_vert != 0 && view->z_vect_angle_vert != 180)
		view->z_vect_angle_hor = (view->z_vect_angle_hor + rotation) % 360;
	upd_all_abs(plane, view);
}

int	upd_ord_vector(int angle_hor, int angle_vert, int scale)
{
	int	ord;

	ord = 0;
	if (angle_hor != 0 && angle_hor != 180)
	{
		if (angle_vert > 90 && angle_vert < 270)
		{
			if (angle_vert < 180)
				ord = (int)(((cos(180 - angle_vert) * M_PI / 180) * scale) * (-1));
			else
				ord = (int)(((cos(angle_vert - 180) * M_PI / 180) * scale) * (-1));
		}
		else
		{
			if (angle_vert <= 90)
				ord = (int)((cos(angle_vert * M_PI / 180)) * scale);
			else
			{
				printf("(360 - angle_vert) * M_PI / 180 = %f\n", (360 - angle_vert) * M_PI / 180);
				ft_printf("%?32s = %d\n", "angle_vert ", angle_vert);
				printf("(cos(360 - angle_vert) * M_PI / 180) = %f\n", (cos(360 - angle_vert) * M_PI / 180));
				printf("(cos(360 - angle_vert) * M_PI / 180) = %f\n", (cos(360 - angle_vert) * M_PI / 180));
				printf("scale = %d\n", scale);
				ord = (int)((cos(360 - angle_vert) * M_PI / 180) * scale);
				printf("ord = %d\n", ord);
			}
		}
	}
	return (ord);
}

void	upd_all_ord(t_plane plane, t_view *view)
{
	ft_printf("---%?32s", "Changing x\n");
	ft_printf("bf, view->x_vect_ord = %d\n", view->x_vect_ord);
	view->x_vect_ord = upd_ord_vector(view->x_vect_angle_hor, view->x_vect_angle_vert, plane.x_scale);
	ft_printf("af, view->x_vect_ord = %d\n", view->x_vect_ord);
	ft_printf("---%?33s", "Changing y\n");
	ft_printf("view->y_vect_ord = %d\n", view->y_vect_ord);
	view->y_vect_ord = upd_ord_vector(view->y_vect_angle_hor, view->y_vect_angle_vert, plane.y_scale);
	ft_printf("view->y_vect_ord = %d\n", view->y_vect_ord);
	ft_printf("---%?34s", "Changing z\n");
	ft_printf("view->z_vect_ord = %d\n", view->z_vect_ord);
	view->z_vect_ord = upd_ord_vector(view->z_vect_angle_hor, view->z_vect_angle_vert, plane.z_scale);
	ft_printf("view->z_vect_ord = %d\n", view->z_vect_ord);
}

void	rotation_hor(t_plane plane, t_view *view, int rotation)
{
	while (rotation < 0)
		rotation += 360;
	while (rotation > 360)
		rotation -= 360;
	if (view->x_vect_angle_hor != 0 && view->x_vect_angle_hor != 180)
		view->x_vect_angle_vert = (view->x_vect_angle_vert + rotation) % 360;
	if (view->y_vect_angle_hor != 0 && view->y_vect_angle_hor != 180)
		view->y_vect_angle_vert = (view->y_vect_angle_vert + rotation) % 360;
	if (view->z_vect_angle_hor != 0 && view->z_vect_angle_hor != 180)
		view->z_vect_angle_vert = (view->z_vect_angle_vert + rotation) % 360;
	upd_all_ord(plane, view);
}

void	init_plane(t_map map, t_plane *plane)
{
	t_view	*view;

	plane->x_scale = 100;
	plane->y_scale = 100;
	plane->z_scale = 100;
	view = (t_view *)malloc(sizeof(t_view));
	if (view == NULL)
		exit (EXIT_FAILURE);
	init_view_1(*plane, view);
	ft_printf("bf vert rot, view->x_vect_angle_hor = %d\n", view->x_vect_angle_hor);
	ft_printf("bf vert rot, view->x_vect_angle_vert = %d\n", view->x_vect_angle_vert);
	ft_printf("bf vert rot, view->y_vect_angle_hor = %d\n", view->y_vect_angle_hor);
	ft_printf("bf vert rot, view->y_vect_angle_vert = %d\n", view->y_vect_angle_vert);
	ft_printf("bf vert rot, view->z_vect_angle_hor = %d\n", view->z_vect_angle_hor);
	ft_printf("bf vert rot, view->z_vect_angle_vert = %d\n", view->z_vect_angle_vert);
	// ATTENTION dimension window 142
	// rotation_vert(*plane, view, 0);
	rotation_hor(*plane, view, 70);
	ft_printf("af vert rot, x_abs = %d\n", view->x_vect_abs);
	ft_printf("af vert rot, y_abs = %d\n", view->y_vect_abs);
	ft_printf("af vert rot, z_abs = %d\n", view->z_vect_abs);
	ft_printf("af vert rot, view->x_vect_angle_hor = %d\n", view->x_vect_angle_hor);
	ft_printf("af vert rot, view->x_vect_angle_vert = %d\n", view->x_vect_angle_vert);
	ft_printf("af vert rot, view->y_vect_angle_hor = %d\n", view->y_vect_angle_hor);
	ft_printf("af vert rot, view->y_vect_angle_vert = %d\n", view->y_vect_angle_vert);
	ft_printf("af vert rot, view->z_vect_angle_hor = %d\n", view->z_vect_angle_hor);
	ft_printf("af vert rot, view->z_vect_angle_vert = %d\n", view->z_vect_angle_vert);
	plane->view = view;
	plane->margin_abs = (int)fmax((float)view->x_vect_abs, (float)view->y_vect_abs);
	if (plane->margin_abs > 20)
		plane->margin_abs = 20;
	plane->margin_ord = (int)fmin((float)view->z_vect_ord, 20);
	plane->height = init_plane_height(map, plane, *view);
	plane->width = init_plane_width(map, plane, *view);
}
