/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:23:49 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/21 16:29:52 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./Libft/libft.h"
# include "./Minilibx/mlx.h"
# include "./Minilibx/mlx_int.h"
# include <X11/keysym.h>
# include <math.h>

typedef struct s_data
{
	int		prev_x;
	int		prev_y;
	int		prev_z_in_x;
	char	**prev_z_in_y;
	int		cur_x;
	int		cur_y;
	int		cur_z;
}			t_data;

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

typedef struct s_plan
{
	int o_abs;
	int o_ord;
	int x_abs;
	int x_ord;
	int y_abs;
	int y_ord;
	int z_abs;
	int z_ord;
}		t_plan;

int		main(int argc, char **argv);
void	check_file_ext(char *str);
void	parse_file(char *file, t_file *infos);
void	infos_init(t_file *infos);
t_img	*init_image(t_xvar **connect, t_file *infos, t_plan *plane);
int		handle_key_input(int keysym, t_xvar **connect);
void	create_plane(t_plan *plane, t_file *infos, int height);
void	create_image(t_xvar **connect, t_img **img, char *file, t_plan *plane);
void	line_up_up_bresenham(t_img *img, t_plan plane, int abs, int ord);
void	line_up_left_bresenham(t_img *img, t_plan plane, int abs, int ord);
void	line_down_down_bresenham(t_img *img, t_plan plane, int abs, int ord);
void	line_down_left_bresenham(t_img *img, t_plan plane, int abs, int ord);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	open_window(t_xvar **connect, t_file *infos, int width, int height);
int		close_window(t_xvar **connect);
void	clean_and_exit(t_xvar **connect, t_img **img);
void	free_tab(char **tab);

#endif
