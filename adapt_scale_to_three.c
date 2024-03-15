/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapt_scale_to_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:59:57 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/15 15:42:07 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	adapt_scale_to_three(t_plane *plane)
{
	if (plane->x->scale < 3)
		plane->x->scale = 3;
	if (plane->y->scale < 3)
		plane->y->scale = 3;
	if (plane->z->scale < 3)
		plane->z->scale = 3;
	plane->h_rot = 70;
	upd_all_abs(plane);
	upd_all_ord(plane);
}
