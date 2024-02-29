/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:47:35 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/23 11:15:52 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || y < 0 || x > img->width || y > img->height)
		return ;
	offset = (x * (img->bpp / 8) + y * img->size_line);
	dst = img->data + offset;
	*(int *)dst = color;
}
