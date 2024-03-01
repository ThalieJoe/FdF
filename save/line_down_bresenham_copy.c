/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_down_bresenham.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:12:45 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/22 17:23:28 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_down_down_bresenham(t_img *img, t_coord coord, int abs, int ord)
{
	int	dx;
	int	dy;
	int	p;

	ft_printf("HERE in line down down bres\n");
	dx = ft_valabs(abs - coord.abs);
	dy = ft_valabs(ord - coord.ord);
	p = 2 * dx - dy;
	while (coord.ord < ord)
	{
		my_pixel_put(img, coord.abs, coord.ord, 0x0000FF);
		coord.ord++;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			coord.abs++;
		}
	}
}

void	line_down_left_bresenham(t_img *img, t_coord coord, int abs, int ord)
{
	int	dx;
	int	dy;
	int	p;


	dx = ft_valabs(abs - coord.abs);
	dy = ft_valabs(ord - coord.ord);
	p = 2 * dy - dx;
	while (coord.abs < abs)
	{
		my_pixel_put(img, coord.abs, coord.ord, 0x00FF00);
		coord.abs++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * dy - 2 * dx;
			coord.ord++;
		}
	}
}
