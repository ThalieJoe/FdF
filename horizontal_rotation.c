/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:54:08 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/12 11:52:38 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void upd_angles(t_vect *vect, int rotation)
{
    vect->v_angle = (vect->v_angle + rotation) % 360;
    if ((vect->h_angle < 180 && vect->v_angle > 180)
        vect->h_angle = vect->v_angle;
    if (vect->h_angle > 180 && vect->v_angle < 180))
        vect->h_angle = vect->v_angle - 90;
}

void    horizontal_rotation(t_plane *plane, int rotation)
{
    while (rotation < 0)
        rotation += 360;
    while (rotation >= 360)
        rotation -= 360;
    if (plane->x->h_angle % 180 != 0)
        upd_angles(plane->x, rotation);
    if (plane->y->h_angle % 180 != 0)
        upd_angles(plane->y, rotation);
    if (plane->z->h_angle % 180 != 0)
        upd_angles(plane->z, rotation);
    upd_all_ord(plane);
}
