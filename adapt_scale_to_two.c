/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapt_scale_to_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:59:57 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/11 13:07:51 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	adapt_scale_to_two(t_plane *plane)
{
	if (plane->x->scale == 0)
		plane->x->scale = 2;
	if (plane->y->scale == 0)
		plane->y->scale = 2;
	if (plane->z->scale == 0)
		plane->z->scale = 2;
}
