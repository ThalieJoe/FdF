/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vertical_margin.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:55:55 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/12 17:12:08 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_vertical_margin(t_plane plane)
{
	int	margin;

	margin = 20;
	if ((margin * 2) + plane.height > 1050)
		margin = (1050 - plane.height) / 2;
	return (margin);
}
