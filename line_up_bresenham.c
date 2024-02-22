/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_up_bresenham.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:11:47 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/21 16:04:08 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_up_up_bresenham(t_img *img, t_plan plane, int abs, int ord)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(abs - plane.o_abs);
	dy = ft_valabs(ord - plane.o_ord);
	p = 2 * dx - dy;
	while (plane.o_ord > ord)
	{
		my_pixel_put(img, plane.o_abs, plane.o_ord, 0x0000FF);
		plane.o_ord--;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			plane.o_abs++;
		}
	}
}

void	line_up_left_bresenham(t_img *img, t_plan plane, int abs, int ord)
{
	int	dx;
	int	dy;
	int	p;

	dx = ft_valabs(abs - plane.o_abs);
	dy = ft_valabs(ord - plane.o_ord);
	p = 2 * dy - dx;
	while (plane.o_abs < abs)
	{
		my_pixel_put(img, plane.o_abs, plane.o_ord, 0xFF0000);
		plane.o_abs++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * dy - 2 * dx;
			plane.o_ord--;
		}
	}
}
