
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:23:49 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/13 15:30:50 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./Libft/libft.h"
# include "./Minilibx/mlx.h"
# include "./Minilibx/mlx_int.h"
# include <math.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <fcntl.h>

typedef struct s_grid
{
	char	*name;
	int		fd;
	int		length;
	int		width;
	int		deepest;
	int		highest;
}			t_grid;

typedef struct s_px
{
	int	abs;
	int	ord;
}		t_px;

typedef struct s_vect
{
	int		scale;
	int		abs;
	int		ord;
	t_px	*in_win;
}			t_vect;

typedef struct s_plane
{
	int		v_rot;
	int		h_rot;
	t_vect	*x;
	t_vect	*y;
	t_vect	*z;
	int		width;
	int		height;
	int		h_marg;
	int		v_marg;
	t_px	*o;
}			t_plane;

typedef struct s_coord
{
	int				x;
	int				y;
	int				z;
	t_px			*px;
	long			color;
	struct s_coord	*prev_x;
	struct s_coord	*prev_y;
	struct s_coord	*head;
	struct s_coord	*prev;
	struct s_coord	*next;
}					t_coord;

typedef struct s_image
{
	t_img			*img;
	struct s_image	*next;
}					t_image;

typedef struct s_map
{
	t_xvar	*connect;
	t_image	*image;
	t_grid	grid;
	t_plane	*plane;
	t_coord	*coord;
}			t_map;

int		main(int argc, char **argv);
void	init_map(t_map *map);
void	parse_grid(char *file, t_map *map);
void	parse_line(char *line, t_map *map);
void	add_to_coord(char **elem, t_map *map, char *line);
t_plane	*init_plane(t_grid grid, t_coord **coord);
int		init_plane_width(t_grid grid, t_plane *plane);
int		init_plane_height(t_grid grid, t_plane *plane);
void	adapt_scale_to_three(t_plane *plane);
int		get_height(t_grid grid, t_plane plane);
int		get_depth(t_grid grid, t_plane plane);
void	upd_all_abs(t_plane *plane);
void	upd_all_ord(t_plane *plane);
int		init_horizontal_margin(t_grid grid, t_plane plane);
int		init_vertical_margin(t_grid grid, t_plane plane);
void	create_image(t_map *map);
void	put_plane_in_image(t_grid grid, t_plane *plane);
void	create_map(t_img *img, t_plane plane, t_coord *coord);
void	draw(t_img *img, t_coord coord);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	line_up_up_bresenham(t_img *img, t_px cur, t_px prev, int color);
void	line_up_left_bresenham(t_img *img, t_px cur, t_px prev, int color);
void	line_down_left_bresenham(t_img *img, t_px cur, t_px prev, int color);
void	line_down_down_bresenham(t_img *img, t_px cur, t_px prev, int color);
void	open_window(t_map *map);
int		handle_key_input(int keysym, t_map *map);
void	add_new_image(t_map *map, int width, int height);
void	right_translation(t_map *map);
void	left_translation(t_map *map);
void	up_translation(t_map *map);
void	down_translation(t_map *map);
void	down_rotation(t_map *map);
void	up_rotation(t_map *map);
void	zoom_in(t_map *map);
void	zoom_out(t_map *map);
t_px	*init_pixel(void);
void	free_tab(char **tab);
void	free_plane(t_plane *plane);
void	coord_clear(t_coord **coord);
void	img_clear(t_xvar *connect, t_image **image);
void	free_and_exit(int fd, t_coord **coord, char **elem, char *line);
void	exit_before_window(t_map *map);
void	clean_all(t_map *map);

#endif
