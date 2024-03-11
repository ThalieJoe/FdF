/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:58:57 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/11 17:07:00 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_vect_x(t_plane *plane)
{
	plane->x = (t_vect *)malloc(sizeof(t_vect));
	if (plane->x == NULL)
	{
		free_plane(plane);
		exit (EXIT_FAILURE);
	}
	plane->x->scale = 100;
	plane->x->abs = 0;
	plane->x->ord = 0;
	plane->x->h_angle = 270;
	plane->x->v_angle = 270;
	init_pixel(&plane->x->in_win);
	if (plane->x->in_win == NULL)
	{
		free_plane(plane);
		exit (EXIT_FAILURE);
	}
}

static void	init_vect_y(t_plane *plane)
{
	plane->y = (t_vect *)malloc(sizeof(t_vect));
	if (plane->y == NULL)
	{
		free_plane(plane);
		exit (EXIT_FAILURE);
	}
	plane->y->scale = 100;
	plane->y->abs = plane->y->scale;
	plane->y->ord = 0;
	plane->y->h_angle = 0;
	plane->y->v_angle = 90;
	init_pixel(&plane->y->in_win);
	if (plane->y->in_win == NULL)
	{
		free_plane(plane);
		exit (EXIT_FAILURE);
	}
}

static void	init_vect_z(t_plane *plane)
{
	plane->z = (t_vect *)malloc(sizeof(t_vect));
	if (plane->z == NULL)
	{
		free_plane(plane);
		exit (EXIT_FAILURE);
	}
	plane->z->scale = 100;
	plane->z->abs = 0;
	plane->z->ord = plane->z->scale;
	plane->z->h_angle = 90;
	plane->z->v_angle = 0;
	init_pixel(&plane->z->in_win);
	if (plane->z->in_win == NULL)
	{
		free_plane(plane);
		exit (EXIT_FAILURE);
	}
}

static void	init_rotations(t_grid grid, t_plane *plane)
{
	int	h_rot;
	int	v_rot;

	v_rot = (int)((atan((float)((plane->x->scale * grid.length) / (plane->y->scale * grid.width))) * 180 / M_PI));
	v_rot = 70;
	h_rot = 15;
	vertical_rotation(plane, v_rot);
	horizontal_rotation(plane, h_rot);
}

void	init_plane(t_grid grid, t_plane *plane)
{
	init_vect_x(plane);
	init_vect_y(plane);
	init_vect_z(plane);
	init_rotations(grid, plane);
	plane->h_marg = (int)fmax((float)plane->x->abs, (float)plane->y->abs);
	plane->v_marg = (int)fmin((float)plane->z->ord, 20);
	plane->height = init_plane_height(grid, plane);
	plane->width = init_plane_width(grid, plane);
	init_pixel(&plane->o);
	if (plane->o == NULL)
	{
		free_plane(plane);
		exit (EXIT_FAILURE);
	}
}
