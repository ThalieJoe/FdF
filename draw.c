/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:02:51 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 15:13:00 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_img *img, t_px cur, t_px prev, int color)
{
	int		dx;
	int		dy;
	float	m;

	dx = cur.abs - prev.abs;
	dy = cur.ord - prev.ord;
	if (dx == 0)
		dx = 1;
	m = (float)dy / (float)dx;
	if (m <= -1)
		line_up_up_bresenham(img, cur, prev, color);
	else if (m <= 0)
		line_up_left_bresenham(img, cur, prev, color);
	else if (m <= 1)
		line_down_left_bresenham(img, cur, prev, color);
	else
		line_down_down_bresenham(img, cur, prev, color);
}

void	draw(t_img *img, t_coord coord)
{
	my_pixel_put(img, coord.px->abs, coord.px->ord, coord.color);
	if (coord.prev_x)
		draw_line(img, *(coord.px), *(coord.prev_x->px), coord.prev_x->color);
	if (coord.prev_y)
		draw_line(img, *(coord.px), *(coord.prev_y->px), coord.prev_y->color);
}
