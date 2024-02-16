/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:02:51 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/16 15:51:08 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_img **img, char **line, t_data *pixel)
{
	int	i;

	i = 0;
	while (line[i])
	{
		// ft_printf("line[%d] = %s, pixel->prev_x = %d, pixel->prev_y =%d, pixel->cur_x =%d, pixel->cur_y =%d\n", i, line[i], pixel->prev_x, pixel->prev_y, pixel->cur_x, pixel->cur_y);
		put_pixels_in_image(*img, pixel);
		pixel->cur_x += 10;
		i++;
	}
}
