/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vector_neg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:30:37 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/29 16:32:37 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	vector_down_down_bresenham_neg(t_xvar *connect, t_plane plane, int abs, int ord, int color)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(abs - plane.xorigin_in_win);
	dy = ft_valabs(ord - plane.yorigin_in_win);
	p = 2 * dx - dy;
	while (ord < plane.yorigin_in_win)
	{
		mlx_pixel_put(connect, connect->win_list, abs, ord, color);
		ord++;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			abs++;
		}
	}
}

void	vector_down_left_bresenham_neg(t_xvar *connect, t_plane plane, int abs, int ord, int color)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(abs - plane.xorigin_in_win);
	dy = ft_valabs(ord - plane.yorigin_in_win);
	p = 2 * dy - dx;
	while (abs < plane.xorigin_in_win)
	{
		mlx_pixel_put(connect, connect->win_list, abs, ord, color);
		abs++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * dy - 2 * dx;
			ord++;
		}
	}
}

void	vector_up_up_bresenham_neg(t_xvar *connect, t_plane plane, int abs, int ord, int color)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(abs - plane.xorigin_in_win);
	dy = ft_valabs(ord - plane.yorigin_in_win);
	p = 2 * dx - dy;
	while (ord > plane.yorigin_in_win)
	{
		mlx_pixel_put(connect, connect->win_list, abs, ord, color);
		ord--;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			abs++;
		}
	}
}

void	vector_up_left_bresenham_neg(t_xvar *connect, t_plane plane, int abs, int ord, int color)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(abs - plane.xorigin_in_win);
	dy = ft_valabs(ord - plane.yorigin_in_win);
	p = 2 * dy - dx;
	while (abs < plane.xorigin_in_win)
	{
		mlx_pixel_put(connect, connect->win_list, abs, ord, color);
		abs++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * dy - 2 * dx;
			ord--;
		}
	}
}

void	draw_vector_neg(t_xvar *connect, t_plane plane, int abs, int ord, int color)
{
	float	m;
	int		dx;
	int		dy;

	dx = abs - plane.xorigin_in_win;
	dy = ord - plane.yorigin_in_win;
	if (dx == 0)
		m = dy;
	else
		m = dy / dx;
	if (m <= -1)
		vector_up_up_bresenham_neg(connect, plane, abs, ord, color);
	else if (m <= 0)
		vector_up_left_bresenham_neg(connect, plane, abs, ord, color);
	else if (m <= 1)
		vector_down_left_bresenham_neg(connect, plane, abs, ord, color);
	else
		vector_down_down_bresenham_neg(connect, plane, abs, ord, color);
}
