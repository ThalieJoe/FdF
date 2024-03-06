/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:40:29 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/06 16:01:38 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_up_up_bresenham_pos(t_xvar *connect, t_coord cur, t_coord prev)
{
	// [x] definir dx et dy
	// [x] definir p = 2dx -dy
	// [x] une boucle while valide tant que coord.prev_x.ord n'a pas atteint coord.ord
	// [x] et on put_pixel et on increment coord.prev_x.ord
	// [x] ensuite, en fonction de la valeur de p on reevalue coord_prev_x_abs et p en fonction de la valeur de p
	// perfection [x]
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(cur.abs - prev.abs);
	dy = ft_valabs(cur.ord - prev.ord);
	p = 2 * dx - dy;
	while (prev.ord > cur.ord)
	{
		mlx_pixel_put(connect, connect->win_list, prev.abs, prev.ord, prev.color);
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

void	line_up_left_bresenham_pos(t_xvar *connect, t_coord cur, t_coord prev)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(cur.abs - prev.abs);
	dy = ft_valabs(cur.ord - prev.ord);
	p = 2 * dy - dx;
	while (prev.abs < cur.abs)
	{
		mlx_pixel_put(connect, connect->win_list, prev.abs, prev.ord, prev.color);
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

void	line_down_left_bresenham_pos(t_xvar *connect, t_coord cur, t_coord prev)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(cur.abs - prev.abs);
	dy = ft_valabs(cur.ord - prev.ord);
	p = 2 * dy - dx;
	while (prev.abs < cur.abs)
	{
		mlx_pixel_put(connect, connect->win_list, prev.abs, prev.ord, prev.color);
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

void	line_down_down_bresenham_pos(t_xvar *connect, t_coord cur, t_coord prev)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(cur.abs - prev.abs);
	dy = ft_valabs(cur.ord - prev.ord);
	p = 2 * dx - dy;
	while (prev.ord < cur.ord)
	{
		mlx_pixel_put(connect, connect->win_list, prev.abs, prev.ord, prev.color);
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
