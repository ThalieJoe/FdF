/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:02:51 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/06 15:57:29 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_pos(t_xvar *connect, t_coord cur, t_coord prev)
{
	int		dx;
	int		dy;
	float	m;

	dx = cur.abs - prev.abs;
	dy = cur.ord - prev.ord;
	if (dx == 0)
		dx = 1;
	m = (float)dy / (float)dx;
	printf("m = %f\n", m);
	if (m <= -1)
	{
		ft_printf("BF line_up_up_bresenham_pos\n");
		line_up_up_bresenham_pos(connect, cur, prev);
	}
	else if (m <= 0)
	{
		ft_printf("BF line_up_left_bresenham_pos\n");
		line_up_left_bresenham_pos(connect, cur, prev);
	}
	else if (m <= 1)
	{
		ft_printf("BF line_down_left_bresenham_pos\n");
		line_down_left_bresenham_pos(connect, cur, prev);
	}
	else
	{
		ft_printf("BF line_down_down_bresenham_pos\n");
		line_down_down_bresenham_pos(connect, cur, prev);
	}
}

// static void	draw_vector_prev_y(t_coord coord, int abs, int ord)
// {
// }

// int		mlx_pixel_put(t_xvar *xvar,t_win_list *win,
// 			      int x,int y,int color)

void	draw(t_xvar *connect, t_coord *coord)
{
	int	i;
	// [ ] Creer une boucle pour iterer chacun des nodes coord.
	// [ ] Regarder si coord->prev_x existe et sa position en abs pour draw.
	// [ ] Regarder si coord->prev_x existe et sa position en abs pour draw.
	i = 1;
	while (coord)
	{
		mlx_pixel_put(connect, connect->win_list, coord->abs, coord->ord, coord->color);
		ft_printf("IN LOOP %d, coord->abs = %d, coord->ord = %d\n", i, coord->abs, coord->ord);
		if (coord->prev_x && coord->prev_x->abs <= coord->abs)
		{
			// ft_printf("Before draw_vector_prev_x_pos, coord->prev_x->abs = %d, coord->abs = %d\n", coord->prev_x->abs, coord->abs);
			draw_line_pos(connect, *coord, *(coord->prev_x));
		}
		if (coord->prev_y && coord->prev_y->abs <= coord->abs)
		{
			draw_line_pos(connect, *coord, *(coord->prev_y));
		}
		i++;
		coord = coord->next;
	}
	// if (coord->prev_x && coord->prev_x->abs > coord->abs)
	// {
	// 	ft_printf("Before draw_vector_prev_x_neg, coord->prev_x->abs = %d, coord->abs = %d\n", coord->prev_x->abs, coord->abs);
	// 	draw_line_neg(connect, coord, coord->prev_x);
	// }
	// else if (coord->prev_x && coord->prev_x->abs > coord->abs)
	// 	draw_vector_prev_x_neg(*coord);
}
