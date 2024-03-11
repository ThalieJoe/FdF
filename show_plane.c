/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:08:51 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/11 13:35:32 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// x yellow | y turquoise | z pink
void	show_plane(t_xvar *connect, t_plane plane, t_px o)
{
	mlx_pixel_put(connect, connect->win_list, o.abs, o.ord, 0xFFFF00);
	if (plane.x->abs >= 0)
		draw_vector_pos(connect, o, *(plane.x), 0xAAAA00);
	else
		draw_vector_neg(connect, o, *(plane.x), 0xAAAA00);
	if (plane.y->abs >= 0)
		draw_vector_pos(connect, o, *(plane.y), 0x00AAAA);
	else
		draw_vector_neg(connect, o, *(plane.y), 0x00AAAA);
	if (plane.z->abs >= 0)
		draw_vector_pos(connect, o, *(plane.z), 0xAA00AA);
	else
		draw_vector_neg(connect, o, *(plane.z), 0xAA00AA);
}
