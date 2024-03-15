
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

# include <stdio.h>

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

int		main(int argc, char **argv);
void	parse_grid(char *file, t_grid *grid, t_coord **coord);
void	check_file_ext(char *str);
void	init_grid(char *file, t_grid *grid, int fd);
void	parse_line(char *line, t_grid *grid, t_coord **coord);
void	init_plane(t_grid grid, t_plane *plane, t_coord **coord);
int		init_plane_width(t_grid grid, t_plane *plane);
int		init_plane_height(t_grid grid, t_plane *plane);
int		get_height(t_grid grid, t_plane plane);
int		get_depth(t_grid grid, t_plane plane);
int		init_horizontal_margin(t_grid grid, t_plane plane);
int		init_vertical_margin(t_grid grid, t_plane plane);
t_px 	*init_pixel(t_plane *plane, t_coord **coord);
void	upd_all_abs(t_plane *plane);
void	upd_all_ord(t_plane *plane);
void	adapt_scale_to_three(t_plane *plane);
void	put_plane_in_window(t_xvar *connect, t_grid grid, t_plane *plane);
void	show_plane(t_xvar *connect, t_plane plane, t_px o);
void	draw_vector(t_xvar *connect, t_px o, t_px vect, int color);
int		handle_key_input(int keysym, t_xvar *connect);
void	create_map(t_xvar *connect, t_plane plane, t_coord *coord);
void	add_to_coord(char **elem, t_coord **coord, t_grid *grid, char *line);
void	draw(t_xvar *connect, t_coord coord);
void	line_up_up_bresenham(t_xvar *connect, t_px cur, t_px prev, int color);
void	line_up_left_bresenham(t_xvar *connect, t_px cur, t_px prev, int color);
void	line_down_left_bresenham(t_xvar *connect, t_px cur, t_px prev, int color);
void	line_down_down_bresenham(t_xvar *connect, t_px cur, t_px prev, int color);
void	open_window(t_xvar **connect, t_grid grid, t_plane plane, t_coord **coord);
void	coord_clear(t_coord **coord);
void	free_and_exit(int fd, t_coord **coord, char **elem, char *line);
void	clean_and_exit(t_xvar *connect, t_plane *plane, t_coord **coord, int err);
void	free_tab(char **tab);
void	free_plane(t_plane *plane);

#endif
