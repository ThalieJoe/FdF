/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_up_bresenham.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:11:47 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/20 09:47:46 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_y_up_bresenham(t_img *img, t_data *pixel)
{
	int	dx;
	int	dy;
	int	p;
	int	prevy;
	int	cury;

	prevy = pixel->prev_y;
	cury = pixel->cur_y;
	dx = pixel->cur_x - pixel->prev_x;
	dy = pixel->cur_y - pixel->prev_y;
	p = 2 * dx - dy;
	while (pixel->prev_y < pixel->cur_y)
	{
		if (pixel->prev_y == prevy || pixel->prev_y == cury)
			my_pixel_put(img, pixel->prev_x, pixel->prev_y, 0xFFFFFF);
		else
			my_pixel_put(img, pixel->prev_x, pixel->prev_y, 0x00FF00);
		pixel->prev_y++;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			pixel->prev_x++;
		}
	}
	pixel->prev_y = prevy;
}

void	line_z_up_bresenham(t_img *img, t_data *pixel)
{
	int	dx;
	int	dz;
	int	m;

	ft_printf("prev_x in linezup = %d\n", pixel->prev_x);
	dx = pixel->cur_x - pixel->prev_x;
	dz = pixel->cur_z - pixel->prev_z_in_x;
	ft_printf("dz in linezup = %d\n", dz);
	m = dz / dx;
	ft_printf("m in linezup = %d\n", m);
	if (m > 1)
	{
		ft_printf("[m > 1] in line_z_up_bres pixel->x = %d, pixel->y = %d, pixel->z = %d\n", pixel->cur_x, pixel->cur_y, pixel->cur_z);
		line_slope_above_1(img, pixel);
	}
	else
	{
		ft_printf("[m <= 1] in line_z_up_bres pixel->x = %d, pixel->y = %d, pixel->z = %d\n", pixel->cur_x, pixel->cur_y, pixel->cur_z);
		line_slope_under_1(img, pixel);
	}
}

void	line_slope_under_1(t_img *img, t_data *pixel)
{
	int	dx;
	int	dz;
	int	p;
	int	prevx;
	int	curx;

	prevx = pixel->prev_x;
	curx = pixel->cur_x;
	dx = pixel->cur_x - pixel->prev_x;
	dz = pixel->cur_z - pixel->prev_z_in_x;
	p = 2 * dz - dx;
	while (pixel->prev_x < pixel->cur_x)
	{
		if (pixel->prev_x == prevx || pixel->prev_x == curx)
			my_pixel_put(img, pixel->prev_x, pixel->cur_z, 0xFFFFFF);
		else
			my_pixel_put(img, pixel->prev_x, pixel->cur_z, 0xFF0000);
		pixel->prev_x++;
		if (p > 0)
			p += 2 * dz;
		else
		{
			p += 2 * dz - 2 * dx;
			pixel->prev_z_in_x++;
		}
	}
}

void	line_slope_above_1(t_img *img, t_data *pixel)
{
	int	dx;
	int	dz;
	int	p;
	int	prevz;
	int	curz;

	prevz = pixel->prev_z_in_x;
	curz = pixel->cur_z;
	dx = pixel->cur_x - pixel->prev_x;
	dz = pixel->cur_z - pixel->prev_z_in_x;
	p = 2 * dx - dz;
	while (pixel->prev_z_in_x < pixel->cur_z)
	{
		if (pixel->prev_z_in_x == prevz || pixel->prev_z_in_x == curz)
			my_pixel_put(img, pixel->cur_x, pixel->prev_z_in_x, 0xFFFFFF);
		else
			my_pixel_put(img, pixel->cur_x, pixel->prev_z_in_x, 0x00FF00);
		pixel->prev_z_in_x++;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dz;
			pixel->prev_x++;
		}
	}
	pixel->prev_z_in_x = prevz;
}
