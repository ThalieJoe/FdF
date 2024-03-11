/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upd_abs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:03:36 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/11 14:51:02 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	upd_abs_vector(t_vect *vect)
{
	if (vect->h_angle == 0)
		vect->abs = vect->scale;
	else if (vect->h_angle <= 90)
		vect->abs =(int)(cos(vect->h_angle * M_PI / 180) * vect->scale);
	else if (vect->h_angle < 180)
		vect->abs = (int)((cos((180 - vect->h_angle) * M_PI / 180) * vect->scale) * (-1));
	else if (vect->h_angle == 180)
		vect->abs = vect->scale * (-1);
	else if (vect->h_angle <= 270)
		vect->abs = (int)((cos((vect->h_angle - 180) * M_PI / 180) * vect->scale) * (-1));
	else
		vect->abs = (int)(cos((360 - vect->h_angle) * M_PI / 180) * vect->scale);
}

void	upd_all_abs(t_plane *plane)
{
	if (plane->x->v_angle % 180 != 0)
		upd_abs_vector(plane->x);
	if (plane->y->v_angle % 180 != 0)
		upd_abs_vector(plane->y);
	if (plane->z->v_angle % 180 != 0)
		upd_abs_vector(plane->z);
}
