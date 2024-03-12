/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_horizontal_margin.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:44:18 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/12 17:03:23 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_horizontal_margin(t_plane plane)
{
	int	margin;

	margin = 20;
	if ((margin * 2) + plane.width > 1920)
		margin = (1920 - plane.width) / 2;
	return (margin);
}
