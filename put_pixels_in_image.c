/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels_in_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:39:43 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/16 15:24:54 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixels_in_image(t_img *img, t_data *pixel)
{
	my_pixel_put(img, pixel->cur_x, pixel->cur_y, 0xFFFFFF);
	if (pixel->cur_x)
		line_left_bresenham(img, pixel);
	if (pixel->cur_y)
		line_up_bresenham(img, pixel);
	// pixel->prev_x = pixel->cur_x;
	// pixel->prev_y = pixel->cur_y;
}
