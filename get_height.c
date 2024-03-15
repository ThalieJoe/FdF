/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:30:16 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/15 15:56:04 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Get the newest ord of the highest scaled coordinate
*/
int	get_height(t_grid grid, t_plane plane)
{
	int	height;
	int	scaled_highest;

	scaled_highest = grid.highest * plane.z->ord;
	height = (grid.length * ft_valabs(plane.x->ord)) + scaled_highest;
	return (height);
}
