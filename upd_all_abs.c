/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upd_all_abs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:03:36 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/12 16:45:03 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	upd_all_abs(t_plane *plane)
{
	plane->x->abs = (int)(cos(45 * M_PI / 180) * plane->x->scale);
	plane->y->abs = (int)(cos(45 * M_PI / 180) * plane->y->scale);
	plane->z->abs = 0;
}
