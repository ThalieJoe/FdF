/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vertical_margin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:55:55 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 14:14:34 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_vertical_margin(t_grid grid, t_plane plane)
{
	int	height;
	int	depth;
	int	margin;

	height = get_height(grid, plane);
	depth = get_depth(grid, plane);
	margin = 5;
	if ((margin * 2) + height + depth > 1050)
		margin = (1050 - (height + depth)) / 2;
	return (margin);
}
