/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels_in_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:39:43 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/19 12:16:40 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixels_in_image_from_above(t_img *img, t_data *pixel)
{
	my_pixel_put(img, pixel->cur_x, pixel->cur_y, 0xFFFFFF);
	if (pixel->cur_x)
		line_left_bresenham(img, pixel);
	if (pixel->cur_y)
		line_y_up_bresenham(img, pixel);
}

void	put_pixels_in_image_from_x(t_img *img, t_data *pixel)
{
	my_pixel_put(img, pixel->cur_x, -pixel->cur_z, 0xFFFFFF);
	// if (pixel->cur_y)
	// 	line_z_up_bresenham(img, pixel);
	// ft_printf("in put_pixels_in_image_from_x, pixel->x = %d, pixel->y = %d, pixel->z = %d, pixel->prev_z_in_x = %d\n", pixel->cur_x, pixel->cur_y, pixel->cur_z, pixel->prev_z_in_x);
	// if (pixel->cur_x)
	// 	line_left_bresenham(img, pixel);
	// pixel->prev_x += 10;
	// if (pixel->cur_z && pixel->cur_z != pixel->prev_z_in_x)
	// 	line_z_up_bresenham(img, pixel);
	// pixel->prev_x += 10;
}
