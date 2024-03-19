/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pxl_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:01:49 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 15:11:00 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;
	char	*dst;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	offset = (x * (img->bpp / 8)) + (y * img->size_line);
	dst = img->data + offset;
	*(int *)(dst) = color;
}
