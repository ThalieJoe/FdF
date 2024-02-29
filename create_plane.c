/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:25:31 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/23 16:05:27 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	determine_o_ord(t_plane plane, t_file infos)
{
	float	o_ord;
	float	size_scale;
	float	elems_scale;

	size_scale = (float)(infos.height * infos.scales[2]);
	// printf("size_scale = %f\n", size_scale);
	elems_scale = (float)((infos.size * infos.scales[2]) - (plane.y_ord * infos.lines));
	// printf("infos.size = %d\n", infos.size);
	// printf("plane.y_ord = %d\n", plane.y_ord);
	// printf("infos.lines = %d\n", infos.lines);
	// printf("elems_scale = %f\n", elems_scale);
	o_ord = fminf(size_scale, elems_scale);
	// printf("o_ord = %f\n", o_ord);
	return ((int)o_ord);
}

void	create_plane(t_plane *plane, t_file infos)
{
	double	rad60;
	double	rad30;

	rad60 = 60 * M_PI / 180;
	rad30 = 30 * M_PI / 180;
	plane->x_abs = (int)(cos(rad30) * infos.scales[0]);
	plane->x_ord = (int)(-cos(rad60) * infos.scales[0]);
	plane->y_abs = (int)(cos(rad30) * infos.scales[1]);
	plane->y_ord = (int)(cos(rad60) * infos.scales[1]);
	plane->o_abs = 0;
	plane->o_ord = determine_o_ord(*plane, infos);
	plane->z_abs = plane->o_abs;
	plane->z_ord = -infos.scales[2];
	ft_printf("plane->x_ord = %?33d\n", plane->x_ord);
}
