/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:23:49 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/01 16:53:40 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>

# include "./Libft/libft.h"
# include "./Minilibx/mlx.h"
# include "./Minilibx/mlx_int.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdbool.h>

typedef struct s_coord
{
	int				x;
	int				y;
	int				z;
	int				abs;
	int				ord;
	struct s_coord	*prev_x;
	struct s_coord	*prev_y;
	struct s_coord	*next;
}					t_coord;

typedef struct	s_view
{
	int		hor_rot;
	int		vert_rot;
	int		x_vect_abs;
	int		x_vect_ord;
	int		x_vect_angle_hor;
	int		x_vect_angle_vert;
	bool	x_vect_hor_ax;
	bool	x_vect_vert_ax;
	int		y_vect_abs;
	int		y_vect_ord;
	int		y_vect_angle_hor;
	int		y_vect_angle_vert;
	bool	y_vect_hor_ax;
	bool	y_vect_vert_ax;
	int		z_vect_abs;
	int		z_vect_ord;
	int		z_vect_angle_hor;
	int		z_vect_angle_vert;
	bool	z_vect_hor_ax;
	bool	z_vect_vert_ax;
}	t_view;

typedef struct s_plane
{
	int		x_scale;
	int		y_scale;
	int		z_scale;
	t_view	*view;
	int		width;
	int		height;
	int		margin_abs;
	int		margin_ord;
	int		xorigin_in_win;
	int		yorigin_in_win;
}			t_plane;

typedef struct s_map
{
	char	*name;
	int		grid_length;
	int		grid_width;
	int		deepest;
	int		highest;
}			t_map;

typedef struct s_file
{
	char	*name;
	int		lines;
	int		scaled_lines;
	int		elems;
	int		scaled_elems;
	int		size;
	int		height;
	int		depth;
	int		scales[3];
	int		win_margin;
}			t_file;

int		main(int argc, char **argv);
void	check_map(char *file);
void	check_file_ext(char *str);
void	parse_map(char *file, t_map *map);
void	init_plane(t_map map, t_plane *plane);
int		init_plane_width(t_map map, t_plane *plane, t_view view);
int		init_plane_height(t_map map, t_plane *plane, t_view view);
void	vertical_rotation(t_plane plane, t_view *view, int rotation);
void	horizontal_rotation(t_plane plane, t_view *view, int rotation);
void	check_my_axis_x(t_view *view, int hor_rot, int vert_rot);
void	check_my_axis_y(t_view *view, int hor_rot, int vert_rot);
void	check_my_axis_z(t_view *view, int hor_rot, int vert_rot);
void	upd_view_vectors(t_plane plane, t_view *view);
void	put_plane_in_window(t_xvar *connect, t_map map, t_plane *plane);
void	show_plane(t_xvar *connect, t_plane plane, t_view *view);
void	draw_vector_pos(t_xvar *connect, t_plane plane, int abs, int ord, int color);
void	draw_vector_neg(t_xvar *connect, t_plane plane, int abs, int ord, int color);
// ---------------------------- //
// t_plane	*init_map_plane();
// void	infos_init(t_file *infos);
// t_img	*init_image(t_xvar **connect, t_file *infos, t_plane *plane);
// int		handle_key_input(int keysym, t_xvar **connect);
// void	create_plane(t_plane *plane, t_file infos);
// void	create_image(t_xvar **connect, t_img **img, char *file, t_plane *plane);
// void	add_coords(t_coord **coord, char **line, int y);
// void	draw(t_img **img, t_plane plane, t_coord *coord);
// void	line_up_up_bresenham(t_img *img, t_coord coord, int abs, int ord);
// void	line_up_left_bresenham(t_img *img, t_coord coord, int abs, int ord);
// void	line_down_down_bresenham(t_img *img, t_coord coord, int abs, int ord);
// void	line_down_left_bresenham(t_img *img, t_coord coord, int abs, int ord);
// void	my_pixel_put(t_img *img, int x, int y, int color);
void	open_window(t_xvar **connect, t_map map, t_plane plane);
int		close_window(t_xvar **connect);
void	clean_and_exit(t_xvar **connect, t_img **img);
void	free_tab(char **tab);

#endif
