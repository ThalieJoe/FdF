/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:25:31 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/21 17:14:31 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_plane(t_plan *plane, t_file *infos, int height)
{
	double	rad60;
	double	rad30;
	int		hyp;

	rad60 = 60 * M_PI / 180;
	rad30 = 30 * M_PI / 180;
	hyp = (int)sqrt(pow(infos->scaled_elems, 2) + pow(infos->scaled_lines, 2));
	ft_printf("infos->height = %d\ninfos-size = %d\n", infos->height, infos->size);
	ft_printf("height = %d\nhyp = %d\n", height, hyp);
	plane->o_abs = 0;
	plane->o_ord = height / 2;
	plane->x_abs = (int)(cos(rad30) * infos->scales[0]);
	plane->x_ord = (int)(cos(rad60) * infos->scales[0]);
	plane->y_abs = (int)(cos(rad30) * infos->scales[1]);
	plane->y_ord = (int)(cos(rad60) * infos->scales[1]);
	plane->z_abs = plane->o_abs;
	plane->z_ord = infos->scales[2];
}
