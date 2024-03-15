/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_horizontal_margin.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:44:18 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/14 16:35:31 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_horizontal_margin(t_grid grid, t_plane plane)
{
	int	length;
	int	width;
	int	margin;

	length = (grid.length - 1) * plane.x->abs;
	width = (grid.width - 1) * plane.y->abs;
	margin = 5;
	if ((margin * 2) + length + width > 1920)
		margin = (1920 - (length + width)) / 2;
	ft_printf("in init horiz margin, margin = %d and plane.width = %d\n", margin, plane.width);
	return (margin);
}
