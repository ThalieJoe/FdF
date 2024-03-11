/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:23:49 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/11 17:05:31 by stouitou         ###   ########.fr       */
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
	int		h_angle;
	int		v_angle;
	t_px	*in_win;
}			t_vect;

typedef struct s_plane
{
	t_vect	*x;
	t_vect	*y;
	t_vect	*z;
	int		h_marg;
	int		v_marg;
	int		height;
	int		width;
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
	struct s_coord	*next;
}					t_coord;

int		main(int argc, char **argv);
void	check_grid(char *file);
void	check_file_ext(char *str);
void	parse_grid(char *file, t_grid *grid);
void	init_plane(t_grid grid, t_plane *plane);
void	vertical_rotation(t_plane *plane, int rotation);
void	horizontal_rotation(t_plane *plane, int rotation);
int		init_plane_width(t_grid grid, t_plane *plane);
int		init_plane_height(t_grid grid, t_plane *plane);
void 	init_pixel(t_px **pixel);
void	upd_all_abs(t_plane *plane);
void	upd_all_ord(t_plane *plane);
void	adapt_scale_to_two(t_plane *plane);
void	put_plane_in_window(t_xvar *connect, t_grid grid, t_plane *plane);
void	show_plane(t_xvar *connect, t_plane plane, t_px o);
void	draw_vector_pos(t_xvar *connect, t_px o, t_vect vect, int color);
void	draw_vector_neg(t_xvar *connect, t_px o, t_vect vect, int color);
int		handle_key_input(int keysym, t_xvar *connect);
void	create_map(t_xvar *connect, t_grid grid, t_plane plane);
void	add_to_coord(t_xvar *connect, char **elem, t_coord **coord, t_plane plane);
void	draw(t_xvar *connect, t_coord *coord);
void	line_up_up_bresenham_pos(t_xvar *connect, t_px cur, t_coord prev);
void	line_up_left_bresenham_pos(t_xvar *connect, t_px cur, t_coord prev);
void	line_down_left_bresenham_pos(t_xvar *connect, t_px cur, t_coord prev);
void	line_down_down_bresenham_pos(t_xvar *connect, t_px cur, t_coord prev);
void	open_window(t_xvar **connect, t_grid grid, t_plane plane);
int		close_window(t_xvar *connect);
void	coord_clear(t_coord **coord);
void	clean_and_exit(t_xvar *connect, int err);
void	free_tab(char **tab);
void	free_plane(t_plane *plane);

#endif
