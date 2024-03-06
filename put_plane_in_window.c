/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_plane_in_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:16:46 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/06 15:15:39 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_vectors_coordinates(t_plane *plane)
{
	plane->x_abs_in_win = plane->xorigin_in_win + plane->view->x_vect_abs;
	plane->x_ord_in_win = plane->yorigin_in_win - plane->view->x_vect_ord;
	plane->y_abs_in_win = plane->xorigin_in_win + plane->view->y_vect_abs;
	plane->y_ord_in_win = plane->yorigin_in_win - plane->view->y_vect_ord;
	plane->z_abs_in_win = plane->xorigin_in_win + plane->view->z_vect_abs;
	plane->z_ord_in_win = plane->yorigin_in_win - plane->view->z_vect_ord;
	// ft_printf("af: plane->view->x_vect_abs = %d\n", plane->view->x_vect_abs);
	// ft_printf("af: plane->view->x_vect_ord = %d\n", plane->view->x_vect_ord);
	// ft_printf("af: plane->view->y_vect_abs = %d\n", plane->view->y_vect_abs);
	// ft_printf("af: plane->view->y_vect_ord = %d\n", plane->view->y_vect_ord);
	// ft_printf("af: plane->view->z_vect_abs = %d\n", plane->view->z_vect_abs);
	// ft_printf("af: plane->view->z_vect_ord = %d\n", plane->view->z_vect_ord);
}

void	put_plane_in_window(t_xvar *connect, t_map map, t_plane *plane)
{
	//plane->xorigin_in_win = plane->margin_abs;
	plane->xorigin_in_win = 200;
	// plane->yorigin_in_win = (map.highest * plane->view->z_vect_ord) + plane->margin_ord;
	plane->yorigin_in_win = 400;
	if (plane->margin_ord < 0 && map.highest > map.deepest * -1)
		plane->yorigin_in_win = 1050 - 50;
	// ft_printf("plane->xorigin_in_win = %d\n", plane->xorigin_in_win);
	// ft_printf("plane->yorigin_in_win = %d\n", plane->yorigin_in_win);
	// ft_printf("av update, x abs  = %d\n", plane->view->x_vect_abs);
	// ft_printf("av update, x ord  = %d\n", plane->view->x_vect_ord);
	// ft_printf("av update, y abs  = %d\n", plane->view->y_vect_abs);
	// ft_printf("av update, y ord  = %d\n", plane->view->y_vect_ord);
	// ft_printf("av update, z abs  = %d\n", plane->view->z_vect_abs);
	// ft_printf("av update, z ord  = %d\n", plane->view->z_vect_ord);
	init_vectors_coordinates(plane);
	// ft_printf("af update, x abs  = %d\n", plane->view->x_vect_abs);
	// ft_printf("af update, x ord  = %d\n", plane->view->x_vect_ord);
	// ft_printf("af update, y abs  = %d\n", plane->view->y_vect_abs);
	// ft_printf("af update, y ord  = %d\n", plane->view->y_vect_ord);
	// ft_printf("af update, z abs  = %d\n", plane->view->z_vect_abs);
	// ft_printf("af update, z ord  = %d\n", plane->view->z_vect_ord);
	show_plane(connect, *plane, plane->view);
}

	// ft_printf("plane->xorigin_in_win = %d\n", plane->xorigin_in_win);
	// ft_printf("plane->yorigin_in_win = %d\n", plane->yorigin_in_win);
