/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:23:49 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/19 16:49:43 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./Libft/libft.h"
# include "./Minilibx/mlx.h"
# include "./Minilibx/mlx_int.h"
# include <X11/keysym.h>

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
	int	lines;
	int	elems;
	int	size;
	int	height;
	int	depth;
}		t_file;

int		main(int argc, char **argv);
void	check_file_ext(char *str);
void	parse_file(char *file, t_file *infos);
t_img	*init_image(t_xvar **connect);
int		handle_key_input(int keysym, t_xvar **connect);
void	create_image(t_xvar **connect, t_img **img, char *file);
void	draw(t_img **img, char **line, t_data *pixel);
void	put_pixels_in_image_from_above(t_img *img, t_data *pixel);
void	put_pixels_in_image_from_x(t_img *img, t_data *pixel);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	line_left_bresenham(t_img *img, t_data *pixel);
void	line_y_up_bresenham(t_img *img, t_data *pixel);
void	line_z_up_bresenham(t_img *img, t_data *pixel);
void	line_slope_under_1(t_img *img, t_data *pixel);
void	line_slope_above_1(t_img *img, t_data *pixel);
void	open_window(t_xvar **connect);
int		close_window(t_xvar **connect);
void	clean_and_exit(t_xvar **connect, t_img **img);
void	free_tab(char **tab);

#endif
