/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:40:29 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/11 14:59:18 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_up_up_bresenham_pos(t_xvar *connect, t_px cur, t_coord prev)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(cur.abs - prev.px->abs);
	dy = ft_valabs(cur.ord - prev.px->ord);
	p = 2 * dx - dy;
	while (prev.px->ord > cur.ord)
	{
		mlx_pixel_put(connect, connect->win_list, prev.px->abs, prev.px->ord, prev.color);
		prev.px->ord--;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			prev.px->abs++;
		}
	}
}

void	line_up_left_bresenham_pos(t_xvar *connect, t_px cur, t_coord prev)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(cur.abs - prev.px->abs);
	dy = ft_valabs(cur.ord - prev.px->ord);
	p = 2 * dy - dx;
	while (prev.px->abs < cur.abs)
	{
		mlx_pixel_put(connect, connect->win_list, prev.px->abs, prev.px->ord, prev.color);
		prev.px->abs++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * dy - 2 * dx;
			prev.px->ord--;
		}
	}
}

void	line_down_left_bresenham_pos(t_xvar *connect, t_px cur, t_coord prev)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(cur.abs - prev.px->abs);
	dy = ft_valabs(cur.ord - prev.px->ord);
	p = 2 * dy - dx;
	while (prev.px->abs < cur.abs)
	{
		mlx_pixel_put(connect, connect->win_list, prev.px->abs, prev.px->ord, prev.color);
		prev.px->abs++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * dy - 2 * dx;
			prev.px->ord++;
		}
	}
}

void	line_down_down_bresenham_pos(t_xvar *connect, t_px cur, t_coord prev)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(cur.abs - prev.px->abs);
	dy = ft_valabs(cur.ord - prev.px->ord);
	p = 2 * dx - dy;
	while (prev.px->ord < cur.ord)
	{
		mlx_pixel_put(connect, connect->win_list, prev.px->abs, prev.px->ord, prev.color);
		prev.px->ord++;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			prev.px->abs++;
		}
	}
}
