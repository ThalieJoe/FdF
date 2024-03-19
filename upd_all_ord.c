/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upd_all_ord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:14:50 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 14:12:05 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	upd_all_ord(t_plane *pl)
{
	int	x_dist_to_h_axis;
	int	y_dist_to_h_axis;

	x_dist_to_h_axis = (int)sqrt(pow(pl->x->scale, 2) - pow(pl->x->abs, 2));
	y_dist_to_h_axis = (int)sqrt(pow(pl->y->scale, 2) - pow(pl->y->abs, 2));
	pl->x->ord = (int)(sin((pl->h_rot) * M_PI / 180) * x_dist_to_h_axis);
	pl->y->ord = (int)((sin(pl->h_rot * M_PI / 180) * y_dist_to_h_axis) * (-1));
	pl->z->ord = (int)(cos(pl->h_rot * M_PI / 180) * pl->z->scale);
}
