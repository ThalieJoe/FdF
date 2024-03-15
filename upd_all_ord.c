/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upd_all_ord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:14:50 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/13 15:48:06 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	upd_all_ord(t_plane *plane)
{
	int	x_dist_to_h_axis;
	int	y_dist_to_h_axis;

	x_dist_to_h_axis = (int)sqrt(pow(plane->x->scale, 2) - pow(plane->x->abs, 2));
	y_dist_to_h_axis = (int)sqrt(pow(plane->y->scale, 2) - pow(plane->y->abs, 2));
	plane->x->ord = (int)(sin((plane->h_rot) * M_PI / 180) * x_dist_to_h_axis);
	plane->y->ord = (int)((sin(plane->h_rot * M_PI / 180) * y_dist_to_h_axis) * (-1));
	plane->z->ord = (int)(cos(plane->h_rot * M_PI / 180) * plane->z->scale);
}
