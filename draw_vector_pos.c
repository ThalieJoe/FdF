/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vector_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:30:37 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/11 13:34:19 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	vector_down_down_bresenham_pos(t_xvar *connect, t_px o, t_vect vect, int color)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(vect.abs - o.abs);
	dy = ft_valabs(vect.ord - o.ord);
	p = 2 * dx - dy;
	while (o.ord < vect.ord)
	{
		mlx_pixel_put(connect, connect->win_list, o.abs, o.ord, color);
		o.ord++;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			o.abs++;
		}
	}
}

static void	vector_down_left_bresenham_pos(t_xvar *connect, t_px o, t_vect vect, int color)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(vect.abs - o.abs);
	dy = ft_valabs(vect.ord - o.ord);
	p = 2 * dy - dx;
	while (o.abs < vect.abs)
	{
		mlx_pixel_put(connect, connect->win_list, o.abs, o.ord, color);
		o.abs++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * dy - 2 * dx;
			o.ord++;
		}
	}
}

static void	vector_up_up_bresenham_pos(t_xvar *connect, t_px o, t_vect vect, int color)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(vect.abs - o.abs);
	dy = ft_valabs(vect.ord - o.ord);
	p = 2 * dx - dy;
	while (o.ord > vect.ord)
	{
		mlx_pixel_put(connect, connect->win_list, o.abs, o.ord, color);
		o.ord--;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			o.abs++;
		}
	}
}

static void	vector_up_left_bresenham_pos(t_xvar *connect, t_px o, t_vect vect, int color)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(vect.abs - o.abs);
	dy = ft_valabs(vect.ord - o.ord);
	p = 2 * dy - dx;
	while (o.abs < vect.abs)
	{
		mlx_pixel_put(connect, connect->win_list, o.abs, o.ord, color);
		o.abs++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * dy - 2 * dx;
			o.ord--;
		}
	}
}

void	draw_vector_pos(t_xvar *connect, t_px o, t_vect vect, int color)
{
	float	m;
	int		dx;
	int		dy;

	dx = vect.abs - o.abs;
	dy = vect.ord - o.ord;
	if (dx == 0)
		m = dy;
	else
		m = (float)dy / (float)dx;
	if (m <= -1)
		vector_up_up_bresenham_pos(connect, o, vect, color);
	else if (m <= 0)
		vector_up_left_bresenham_pos(connect, o, vect, color);
	else if (m <= 1)
		vector_down_left_bresenham_pos(connect, o, vect, color);
	else
		vector_down_down_bresenham_pos(connect, o, vect, color);
}
