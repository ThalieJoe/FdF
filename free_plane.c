/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:32:37 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/18 13:47:45 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_plane(t_plane *plane)
{
	if (plane->x)
		free(plane->x->in_win);
	if (plane->y)
		free(plane->y->in_win);
	if (plane->z)
		free(plane->z->in_win);
	free(plane->x);
	free(plane->y);
	free(plane->z);
	free(plane->o);
	free(plane);
	plane = NULL;
}
