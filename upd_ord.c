/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upd_ord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:14:50 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/11 14:51:21 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	upd_ord_vector(t_vect *vect)
{
	if (vect->v_angle == 0)
		vect->ord = vect->scale;
	else if (vect->v_angle <= 90)
		vect->ord = (int)((cos(vect->v_angle * M_PI / 180)) * vect->scale);
	else if (vect->v_angle < 180)
		vect->ord = (int)(((cos((180 - vect->v_angle) * M_PI / 180)) * vect->scale) * (-1));
	else if (vect->v_angle == 180)
		vect->ord = -vect->scale;
	else if (vect->v_angle < 270)
		vect->ord = (int)(((cos((vect->v_angle - 180) * M_PI / 180)) * vect->scale) * (-1));
	else
		vect->ord = (int)((cos((360 - vect->v_angle) * M_PI / 180)) * vect->scale);
}

void	upd_all_ord(t_plane *plane)
{
	if (plane->x->h_angle % 180 != 0)
		upd_ord_vector(plane->x);
	if (plane->y->h_angle % 180 != 0)
		upd_ord_vector(plane->y);
	if (plane->z->h_angle % 180 != 0)
		upd_ord_vector(plane->z);
}
