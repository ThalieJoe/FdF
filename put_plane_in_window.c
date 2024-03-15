/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_plane_in_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:16:46 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/14 15:50:51 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	draw_horizontal_line(t_xvar *connect, int cur_abs, int prev_abs, int ord)
// {
// 	while (prev_abs < cur_abs)
// 	{
// 		mlx_pixel_put(connect, connect->win_list, prev_abs, ord, 0x444444);
// 		prev_abs++;
// 	}
// }

// static void	draw_vertical_line(t_xvar *connect, t_plane plane)
// {
// 	int	origin;

// 	origin = 0;
// 	while (origin < plane.height + plane.v_marg)
// 	{
// 		mlx_pixel_put(connect, connect->win_list, ((plane.width + (plane.h_marg * 2)) / 2), origin, 0x444444);
// 		origin++;
// 	}
// }

static void	find_coord_in_win(t_vect *vect, t_px origin)
{
	vect->in_win->abs = origin.abs + vect->abs;
	vect->in_win->ord = origin.ord - vect->ord;
}

static void	find_vectors_coordinates(t_plane *plane)
{
	find_coord_in_win(plane->x, *(plane->o));
	find_coord_in_win(plane->y, *(plane->o));
	find_coord_in_win(plane->z, *(plane->o));
}

static void	find_origin_in_win(t_grid grid, t_plane plane, t_px *origin)
{
	origin->abs = plane.h_marg;
	origin->ord = (grid.length * ft_valabs(plane.x->ord)) + (grid.highest * plane.z->ord) + plane.v_marg;
	ft_printf("In find origin in win plane.v_marg = %?33d\n", plane.v_marg);
}

void	put_plane_in_window(t_xvar *connect, t_grid grid, t_plane *plane)
{
	find_origin_in_win(grid, *plane, plane->o);
	// if (plane->v_marg < 0 && grid.highest > grid.deepest * -1)
	// 	plane->o->ord = 1050 - 50;
	find_vectors_coordinates(plane);
	(void)connect;
	// ft_printf("plane->x->in_win->abs = %?33d, plane->x->in_win->ord = %?33d\n", plane->x->in_win->abs, plane->x->in_win->ord);
	// ft_printf("plane->y->in_win->abs = %?34d, plane->y->in_win->ord = %?34d\n", plane->y->in_win->abs, plane->y->in_win->ord);
	// ft_printf("plane->z->in_win->abs = %?35d, plane->z->in_win->ord = %?35d\n", plane->z->in_win->abs, plane->z->in_win->ord);
	// show_plane(connect, *plane, *(plane->o));
	// draw_horizontal_line(connect, plane->width + plane->h_marg, plane->h_marg, plane->o->ord);
	// draw_vertical_line(connect, *plane);

}
