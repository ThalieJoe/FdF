/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upd_all_abs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:03:36 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/13 12:00:15 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	upd_all_abs(t_plane *plane)
{
	plane->x->abs = (int)(cos((90 - plane->v_rot) * M_PI / 180) * plane->x->scale);
	plane->y->abs = (int)(cos(plane->v_rot * M_PI / 180) * plane->y->scale);
	plane->z->abs = 0;
}
