/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:32:30 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/23 11:18:41 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_down_down_axis(t_img *img, t_plan plane, int abs, int ord)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(abs - plane.o_abs);
	dy = ft_valabs(ord - plane.o_ord);
	p = 2 * dx - dy;
	while (plane.o_ord < ord)
	{
		my_pixel_put(img, plane.o_abs, plane.o_ord, 0x0000FF);
		plane.o_ord++;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			plane.o_abs++;
		}
	}
}

void	line_down_left_axis(t_img *img, t_plan plane, int abs, int ord)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(abs - plane.o_abs);
	dy = ft_valabs(ord - plane.o_ord);
	p = 2 * dy - dx;
	while (plane.o_abs < abs)
	{
		my_pixel_put(img, plane.o_abs, plane.o_ord, 0x00FF00);
		plane.o_abs++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * dy - 2 * dx;
			plane.o_ord++;
		}
	}
}

static void	line_up_up_axis(t_img *img, t_plan plane, int abs, int ord)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(abs - plane.o_abs);
	dy = ft_valabs(ord - plane.o_ord);
	p = 2 * dx - dy;
	while (plane.o_ord > ord)
	{
		my_pixel_put(img, plane.o_abs, plane.o_ord, 0x0000FF);
		plane.o_ord--;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			plane.o_abs++;
		}
	}
}

static void	line_up_left_axis(t_img *img, t_plan plane, int abs, int ord)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(abs - plane.o_abs);
	dy = ft_valabs(ord - plane.o_ord);
	p = 2 * dy - dx;
	while (plane.o_abs < abs)
	{
		my_pixel_put(img, plane.o_abs, plane.o_ord, 0xFF0000);
		plane.o_abs++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * dy - 2 * dx;
			plane.o_ord--;
		}
	}
}

static void	draw_axis(t_img *img, t_plan plane, int abs, int ord)
{
	float	dx;
	float	dy;
	float	m;

	dx = abs - plane.o_abs;
	dy = ord - plane.o_ord;
	m = dy / dx;
	if (dx == 0)
		m = dy;
	if (m <= -1)
		line_up_up_axis(img, plane, abs, ord);
	else if (m <= 0)
		line_up_left_axis(img, plane, abs, ord);
	else if (m <= 1)
		line_down_left_axis(img, plane, abs, ord);
	else
		line_down_down_axis(img, plane, abs, ord);
}

static void	draw_plane(t_img *img, t_plan *plane)
{
	int	abs;
	int	ord;

	my_pixel_put(img, plane->o_abs, plane->o_ord, 0xFFFFFF);
	abs = plane->o_abs + plane->x_abs;
	ord = plane->o_ord + plane->x_ord;
	my_pixel_put(img, abs, ord, 0xFFFFFF);
	draw_axis(img, *plane, abs, ord);
	abs = plane->o_abs + plane->y_abs;
	ord = plane->o_ord + plane->y_ord;
	my_pixel_put(img, abs, ord, 0xFFFFFF);
	draw_axis(img, *plane, abs, ord);
	abs = plane->o_abs + plane->z_abs;
	ord = plane->o_ord + plane->z_ord;
	my_pixel_put(img, abs, ord, 0xFFFFFF);
	draw_axis(img, *plane, abs, ord);
}

void	create_image(t_xvar **connect, t_img **img, char *file, t_plan *plane)
{
	int		fd;
	int		y;
	char	*str;
	char	**line;
	t_coord	*coord;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close_window(connect);
		clean_and_exit(connect, img);
	}
	draw_plane(*img, plane);
	ft_printf("plane->o_abs = %?31d\n", plane->o_abs);
	ft_printf("plane->o_ord = %?37d\n", plane->o_ord);
	y = 0;
	coord = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		line = ft_split(str, " ");
		add_coords(&coord, line, y);
		free_tab(line);
		free(str);
		y++;
	}
	draw(img, *plane, coord);
}
