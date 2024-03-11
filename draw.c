/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:02:51 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/11 14:58:23 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_pos(t_xvar *connect, t_px cur, t_coord prev)
{
	int		dx;
	int		dy;
	float	m;

	dx = cur.abs - prev.px->abs;
	dy = cur.ord - prev.px->ord;
	if (dx == 0)
		dx = 1;
	m = (float)dy / (float)dx;
	if (m <= -1)
		line_up_up_bresenham_pos(connect, cur, prev);
	else if (m <= 0)
		line_up_left_bresenham_pos(connect, cur, prev);
	else if (m <= 1)
		line_down_left_bresenham_pos(connect, cur, prev);
	else
		line_down_down_bresenham_pos(connect, cur, prev);
}

void	draw(t_xvar *connect, t_coord *coord)
{
	while (coord)
	{
		mlx_pixel_put(connect, connect->win_list, coord->px->abs, coord->px->ord, coord->color);
		if (coord->prev_x && coord->prev_x->px->abs <= coord->px->abs)
			draw_line_pos(connect, *(coord->px), *(coord->prev_x));
		if (coord->prev_y && coord->prev_y->px->abs <= coord->px->abs)
			draw_line_pos(connect, *(coord->px), *(coord->prev_y));
		coord = coord->next;
	}
}
