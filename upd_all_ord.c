/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upd_ord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:14:50 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/12 16:36:28 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	upd_all_ord(t_plane *plane)
{
	plane->x->ord = (int)(cos(75 * M_PI / 180) * plane->x->scale);
	plane->y->ord = (int)((cos(75 * M_PI / 180) * plane->y->scale) * (-1));
	plane->z->ord = (int)(cos(15 * M_PI / 180) * plane->y->scale);
}
