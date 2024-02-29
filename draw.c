/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:02:51 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/23 11:28:23 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_vector_prev_x(t_img *img, t_coord coord, int abs, int ord)
{
	float	dx;
	float	dy;
	float	m;

	ft_printf("HERE in draw vector prev x\n");
	dx = coord.abs - coord.prev_x->abs;
	dy = coord.ord - coord.prev_x->ord;
	m = dy / dx;
	printf("coord.abs = %d\n", coord.abs);
	printf(" coord.prev_x->abs = %d\n",  coord.prev_x->abs);
	printf("coord.ord = %d\n", coord.ord);
	printf(" coord.prev_x->ord = %d\n",  coord.prev_x->ord);
	printf("dx = %f\n", dx);
	printf("dy = %f\n", dy);
	printf("m = %f\n", m);
	if (dx == 0)
		m = dy;
	if (m <= -1)
		line_up_up_bresenham(img, *(coord.prev_x), abs, ord);
	else if (m <= 0)
		line_up_left_bresenham(img, *(coord.prev_x), abs, ord);
	else if (m <= 1)
		line_down_left_bresenham(img, *(coord.prev_x), abs, ord);
	else
		line_down_down_bresenham(img, *(coord.prev_x), abs, ord);
}

static void	draw_vector_prev_y(t_img *img, t_coord coord, int abs, int ord)
{
	float	dx;
	float	dy;
	float	m;

	dx = coord.abs - coord.prev_y->abs;
	dy = coord.ord - coord.prev_y->ord;
	m = dy / dx;
	ft_printf("m = %d\n", m);
	if (dx == 0)
		m = dy;
	if (m <= -1)
		line_up_up_bresenham(img, *(coord.prev_y), abs, ord);
	else if (m <= 0)
		line_up_left_bresenham(img, *(coord.prev_y), abs, ord);
	else if (m <= 1)
		line_down_left_bresenham(img, *(coord.prev_y), abs, ord);
	else
		line_down_down_bresenham(img, *(coord.prev_y), abs, ord);
}

void	draw(t_img **img, t_plan plane, t_coord *coord)
{
	while (coord)
	{
		coord->abs = plane.o_abs + coord->x * plane.x_abs + coord->y * plane.y_abs + coord->z * plane.z_abs;
		coord->ord = plane.o_ord + coord->x * plane.x_ord + coord->y * plane.y_ord + coord->z * plane.z_ord;
		my_pixel_put(*img, coord->abs, coord->ord, 0xFFFFFF);
		// ft_printf("coord->abs = %?33d\n", coord->abs);
		// ft_printf("coord->ord = %?34d\n", coord->ord);
		// if (coord->prev_x)
		// {
		// 	ft_printf("coord->prev_x->abs = %?33d\n", coord->prev_x->abs);
		// 	ft_printf("coord->prev_x->ord = %?34d\n", coord->prev_x->ord);
		// }
		// if (coord->prev_y)
		// {
		// 	ft_printf("coord->prev_y->abs = %?33d\n", coord->prev_y->abs);
		// 	ft_printf("coord->prev_y->ord = %?34d\n", coord->prev_y->ord);
		// }
		if (coord->prev_x)
			draw_vector_prev_x(*img, *coord, coord->abs, coord->ord);
		if (coord->prev_y)
			draw_vector_prev_y(*img, *coord, coord->abs, coord->ord);
		ft_printf("HERE\n");
		coord = coord->next;
	}
}
