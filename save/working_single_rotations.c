void	rotation_vert(t_plane plane, t_view *view)
{
	view->vert_rotation += 60;
	view->x_vect_angle_hor += view->vert_rotation;
	view->x_vect_angle_vert += view->hor_rotation;
	view->y_vect_angle_hor += view->vert_rotation;
	view->y_vect_angle_vert += view->hor_rotation;
	// view->z_vect_angle_hor = -90;
	view->z_vect_angle_vert += view->hor_rotation;
	view->x_vect_abs = (int)(cos(ft_valabs(view->x_vect_angle_hor) * M_PI / 180) * plane.x_scale);
	view->x_vect_ord = (int)(cos(ft_valabs(view->x_vect_angle_vert) * M_PI / 180) * plane.x_scale);
	view->y_vect_abs = (int)(cos(ft_valabs(view->y_vect_angle_hor) * M_PI / 180) * plane.y_scale);
	view->y_vect_ord = (int)(cos(ft_valabs(view->y_vect_angle_vert) * M_PI / 180) * plane.y_scale);
	view->z_vect_abs = 0;
	view->z_vect_ord = (int)(cos(ft_valabs(view->z_vect_angle_vert) * M_PI / 180) * plane.z_scale);
}

void	rotation_hor(t_plane plane, t_view *view)
{
	view->hor_rotation += 60;
	view->x_vect_angle_hor += view->vert_rotation;
	view->x_vect_angle_vert += view->hor_rotation;
	view->y_vect_angle_hor += view->vert_rotation;
	// view->y_vect_angle_vert += view->hor_rotation;
	// view->z_vect_angle_hor = -90;
	view->z_vect_angle_vert += view->hor_rotation;
	view->x_vect_abs = (int)(cos(ft_valabs(view->x_vect_angle_hor) * M_PI / 180) * plane.x_scale);
	view->x_vect_ord = (int)(cos(ft_valabs(view->x_vect_angle_vert) * M_PI / 180) * plane.x_scale);
	view->y_vect_abs = (int)(cos(ft_valabs(view->y_vect_angle_hor) * M_PI / 180) * plane.y_scale);
	view->y_vect_ord = (int)(cos(ft_valabs(view->y_vect_angle_vert) * M_PI / 180) * plane.y_scale);
	view->z_vect_abs = 0;
	view->z_vect_ord = (int)(cos(ft_valabs(view->z_vect_angle_vert) * M_PI / 180) * plane.z_scale);
}
