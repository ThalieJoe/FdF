/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_up_bresenham.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:11:47 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/16 15:54:11 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_up_bresenham(t_img *img, t_data *pixel)
{
	int	dx;
	int	dy;
	int	p;
	int	prevy;
	int	cury;

	prevy = pixel->prev_y;
	cury = pixel->cur_y;
	dx = pixel->cur_x - pixel->prev_x;
	dy = pixel->cur_y - pixel->prev_y;
	p = 2 * dx - dy;
	while (pixel->prev_y < pixel->cur_y)
	{
		ft_printf("pixel->prev_x =%d, pixel->cur_x =%d\n", pixel->prev_x, pixel->cur_x);
		if (pixel->prev_y == prevy || pixel->prev_y == cury)
			my_pixel_put(img, pixel->cur_x, pixel->prev_y, 0xFFFFFF);
		else
			my_pixel_put(img, pixel->cur_x, pixel->prev_y, 0x00FFFA);
		pixel->prev_y++;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			pixel->prev_x++;
		}
	}
	ft_printf("prevy = %d\n", prevy);
	pixel->prev_y = prevy;
}
