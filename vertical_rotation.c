/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:49:43 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/12 12:13:46 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void upd_angles(t_vect *vect, int rotation)
{
    vect->h_angle = (vect->h_angle + rotation) % 360;
    if ((vect->v_angle < 180 && vect->h_angle > 180)
        vect->v_angle = vect->h_angle - 90;
    if (vect->v_angle > 180 && vect->h_angle < 180))
        vect->v_angle = vect->h_angle + 90;
}

void    vertical_rotation(t_plane *plane, int rotation)
{
    while (rotation < 0)
        rotation += 360;
    while (rotation >= 360)
        rotation -= 360;
    if (plane->x->v_angle % 180 != 0)
        upd_angles(plane->x, rotation);
    if (plane->y->v_angle % 180 != 0)
        upd_angles(plane->y, rotation);
    if (plane->z->v_angle % 180 != 0)
        upd_angles(plane->z, rotation);
    upd_all_abs(plane);
}
