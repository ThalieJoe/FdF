/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_up_bresenham_copy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:11:47 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/27 15:00:14 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_up_up_bresenham(t_img *img, t_coord coord, int abs, int ord)
{
	int	dx;
	int	dy;
	int	p;

	ft_printf("HERE in line up up bres\n");
	ft_printf("prev->abs = %d, abs = %d\n", coord.abs, abs);
	ft_printf("prev->ord = %d, ord = %d\n", coord.ord, ord);
	dx = ft_valabs(abs - coord.abs);
	dy = ft_valabs(ord - coord.ord);
	p = 2 * dx - dy;
	while (coord.ord > ord)
	{
		// ft_printf("p au debut de line up up = %d\n", p);
		my_pixel_put(img, coord.abs, coord.ord, 0x0000FF);
		coord.ord--;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			// ft_printf("p apres prev.ord -- = %d\n", p);
			coord.abs++;
		}
	}
}

void	line_up_left_bresenham(t_img *img, t_coord coord, int abs, int ord)
{
	int	dx;
	int	dy;
	int	p;

	ft_printf("HERE in line up left bres\n");
	dx = ft_valabs(abs - coord.abs);
	dy = ft_valabs(ord - coord.ord);
	p = 2 * dy - dx;
	while (coord.abs < abs)
	{
		my_pixel_put(img, coord.abs, coord.ord, 0xFF0000);
		coord.abs++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * dy - 2 * dx;
			coord.ord--;
		}
	}
}
