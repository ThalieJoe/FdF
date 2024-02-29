/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_plane_in_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:16:46 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/29 16:41:49 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	upd_vectors_coordinates(t_plane *plane)
{
	plane->view->x_vect_abs = plane->xorigin_in_win + plane->view->x_vect_abs;
	plane->view->x_vect_ord = plane->yorigin_in_win - plane->view->x_vect_ord;
	plane->view->y_vect_abs = plane->xorigin_in_win + plane->view->y_vect_abs;
	plane->view->y_vect_ord = plane->yorigin_in_win + plane->view->y_vect_ord;
	plane->view->z_vect_abs = plane->xorigin_in_win + plane->view->z_vect_abs;
	plane->view->z_vect_ord = plane->yorigin_in_win - plane->view->z_vect_ord;
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
	upd_vectors_coordinates(plane);
	show_plane(connect, *plane, plane->view);
}

	// ft_printf("plane->xorigin_in_win = %d\n", plane->xorigin_in_win);
	// ft_printf("plane->yorigin_in_win = %d\n", plane->yorigin_in_win);
