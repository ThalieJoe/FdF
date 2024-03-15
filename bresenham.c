/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:40:29 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/13 11:38:29 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_up_up_bresenham(t_xvar *connect, t_px cur, t_px prev, int color)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(cur.abs - prev.abs);
	dy = ft_valabs(cur.ord - prev.ord);
	p = 2 * dx - dy;
	while (prev.ord > cur.ord)
	{
		mlx_pixel_put(connect, connect->win_list, prev.abs, prev.ord, color);
		prev.ord--;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			prev.abs++;
		}
	}
}

void	line_up_left_bresenham(t_xvar *connect, t_px cur, t_px prev, int color)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(cur.abs - prev.abs);
	dy = ft_valabs(cur.ord - prev.ord);
	p = 2 * dy - dx;
	while (prev.abs < cur.abs)
	{
		mlx_pixel_put(connect, connect->win_list, prev.abs, prev.ord, color);
		prev.abs++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * dy - 2 * dx;
			prev.ord--;
		}
	}
}

void	line_down_left_bresenham(t_xvar *connect, t_px cur, t_px prev, int color)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(cur.abs - prev.abs);
	dy = ft_valabs(cur.ord - prev.ord);
	p = 2 * dy - dx;
	while (prev.abs < cur.abs)
	{
		mlx_pixel_put(connect, connect->win_list, prev.abs, prev.ord, color);
		prev.abs++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * dy - 2 * dx;
			prev.ord++;
		}
	}
}

void	line_down_down_bresenham(t_xvar *connect, t_px cur, t_px prev, int color)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(cur.abs - prev.abs);
	dy = ft_valabs(cur.ord - prev.ord);
	p = 2 * dx - dy;
	while (prev.ord < cur.ord)
	{
		mlx_pixel_put(connect, connect->win_list, prev.abs, prev.ord, color);
		prev.ord++;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			prev.abs++;
		}
	}
}
