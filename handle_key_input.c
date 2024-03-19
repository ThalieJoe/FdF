/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:37:24 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 15:18:42 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key_input(int keysym, t_map *map)
{
	if (keysym == XK_Right)
		right_translation(map);
	if (keysym == XK_Left)
		left_translation(map);
	if (keysym == XK_Up)
		up_translation(map);
	if (keysym == XK_Down)
		down_translation(map);
	if (keysym == XK_k)
		down_rotation(map);
	if (keysym == XK_o)
		up_rotation(map);
	if (keysym == XK_KP_Add)
		zoom_in(map);
	if (keysym == XK_KP_Subtract)
		zoom_out(map);
	if (keysym == XK_Escape)
		mlx_loop_end(map->connect);
	return (0);
}
