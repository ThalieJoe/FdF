/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_left_bresenham.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:12:45 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/20 09:46:17 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_left_bresenham(t_img *img, t_data *pixel)
{
	int	dx;
	int	dy;
	int	p;
	int	prevx;
	int	curx;

	prevx = pixel->prev_x;
	curx = pixel->cur_x;
	dx = pixel->cur_x - pixel->prev_x;
	dy = pixel->cur_y - pixel->prev_y;
	p = 2 * dy - dx;
	while (pixel->prev_x < pixel->cur_x)
	{
		if (pixel->prev_x == prevx || pixel->prev_x == curx)
			my_pixel_put(img, pixel->prev_x, pixel->prev_y, 0xFFFFFF);
		else
			my_pixel_put(img, pixel->prev_x, pixel->prev_y, 0xFFFF80);
		pixel->prev_x++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * dy - 2 * dx;
			pixel->prev_y++;
		}
	}
	pixel->prev_x = prevx;
}
