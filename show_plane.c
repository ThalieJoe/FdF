/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:08:51 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/13 11:25:40 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// x yellow | y turquoise | z pink
void	show_plane(t_xvar *connect, t_plane plane, t_px o)
{
	mlx_pixel_put(connect, connect->win_list, o.abs, o.ord, 0xFFFF00);
	draw_vector(connect, o, *(plane.x->in_win), 0xAAAA00);
	draw_vector(connect, o, *(plane.y->in_win), 0x00AAAA);
	draw_vector(connect, o, *(plane.z->in_win), 0xAA00AA);
}
