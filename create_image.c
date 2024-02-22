/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:32:30 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/21 16:04:39 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_axe(t_img *img, t_plan plane, int abs, int ord)
{
	float	dx;
	float	dy;
	float	m;

	dx = abs - plane.o_abs;
	dy = ord - plane.o_ord;
	m = dy / dx;
	if (dx == 0)
		m = -dy;
	if (m >= 1)
		line_up_up_bresenham(img, plane, abs, ord);
	else if (m >= 0)
		line_up_left_bresenham(img, plane, abs, ord);
	else if (m >= -1)
		line_down_left_bresenham(img, plane, abs, ord);
	else
		line_down_down_bresenham(img, plane, abs, ord);
}

static void	draw_plane(t_img *img, t_plan *plane)
{
	int	abs;
	int	ord;

	my_pixel_put(img, plane->o_abs, plane->o_ord, 0xFFFFFF);
	abs = plane->o_abs + plane->x_abs;
	ord = plane->o_ord - plane->x_ord;
	my_pixel_put(img, abs, ord, 0xFFFFFF);
	draw_axe(img, *plane, abs, ord);
	abs = plane->o_abs + plane->y_abs;
	ord = plane->o_ord + plane->y_ord;
	my_pixel_put(img, abs, ord, 0xFFFFFF);
	draw_axe(img, *plane, abs, ord);
	abs = plane->o_abs + plane->z_abs;
	ord = plane->o_ord - plane->z_ord;
	my_pixel_put(img, abs, ord, 0xFFFFFF);
	draw_axe(img, *plane, abs, ord);
}

void	create_image(t_xvar **connect, t_img **img, char *file, t_plan *plane)
{
	int		fd;
	char	*str;
	char	**line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close_window(connect);
		clean_and_exit(connect, img);
	}
	draw_plane(*img, plane);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		line = ft_split(str, " ");
	}
}
