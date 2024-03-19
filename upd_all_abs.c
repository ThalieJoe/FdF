/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upd_all_abs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:03:36 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 14:11:46 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	upd_all_abs(t_plane *pl)
{
	pl->x->abs = (int)(cos((90 - pl->v_rot) * M_PI / 180) * pl->x->scale);
	pl->y->abs = (int)(cos(pl->v_rot * M_PI / 180) * pl->y->scale);
	pl->z->abs = 0;
}
