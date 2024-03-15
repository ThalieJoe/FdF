/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_depth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:31:37 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/15 15:58:46 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Get the newest ord of the deepest scaled coordinate
*/
int	get_depth(t_grid grid, t_plane plane)
{
	int	depth;
	int	scaled_deepest;

	scaled_deepest = grid.deepest * plane.z->ord;
	depth = (grid.width * plane.y->ord) + scaled_deepest;
	return (depth * (-1));
}
