/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:58:57 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 14:07:37 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Allocate memory for X vector and for pixel structure in it
Initialize values of vector structure in plane
*/
static void	init_vect_x(t_plane *pl, t_coord **coord)
{
	int	dist_to_h_axis;

	pl->x = (t_vect *)malloc(sizeof(t_vect));
	if (pl->x == NULL)
	{
		free_plane(pl);
		coord_clear(coord);
		exit (EXIT_FAILURE);
	}
	pl->x->scale = 100;
	pl->x->abs = (int)(cos((90 - pl->v_rot) * M_PI / 180) * pl->x->scale);
	dist_to_h_axis = (int)sqrt(pow(pl->x->scale, 2) - pow(pl->x->abs, 2));
	pl->x->ord = (int)(sin((pl->h_rot) * M_PI / 180) * dist_to_h_axis);
	pl->x->in_win = init_pixel();
	if (pl->x->in_win == NULL)
	{
		free_plane(pl);
		coord_clear(coord);
		exit (EXIT_FAILURE);
	}
}

/*
Allocate memory for Y vector and for pixel structure in it
Initialize values of vector structure in pl
*/
static void	init_vect_y(t_plane *pl, t_coord **coord)
{
	int	dist_to_h_axis;

	pl->y = (t_vect *)malloc(sizeof(t_vect));
	if (pl->y == NULL)
	{
		free_plane(pl);
		coord_clear(coord);
		exit (EXIT_FAILURE);
	}
	pl->y->scale = 100;
	pl->y->abs = (int)(cos((pl->v_rot) * M_PI / 180) * pl->y->scale);
	dist_to_h_axis = (int)sqrt(pow(pl->y->scale, 2) - pow(pl->y->abs, 2));
	pl->y->ord = (int)((sin(pl->h_rot * M_PI / 180) * dist_to_h_axis) * (-1));
	pl->y->in_win = init_pixel();
	if (pl->y->in_win == NULL)
	{
		free_plane(pl);
		coord_clear(coord);
		exit (EXIT_FAILURE);
	}
}

/*
Allocate memory for Z vector and for pixel structure in it
Initialize values of vector structure in pl
*/
static void	init_vect_z(t_plane *pl, t_coord **coord)
{
	pl->z = (t_vect *)malloc(sizeof(t_vect));
	if (pl->z == NULL)
	{
		free_plane(pl);
		coord_clear(coord);
		exit (EXIT_FAILURE);
	}
	pl->z->scale = 100;
	pl->z->abs = 0;
	pl->z->ord = (int)(cos(pl->h_rot * M_PI / 180) * pl->z->scale);
	pl->z->in_win = init_pixel();
	if (pl->z->in_win == NULL)
	{
		free_plane(pl);
		coord_clear(coord);
		exit (EXIT_FAILURE);
	}
}

static int	init_horizontal_rotation(t_grid grid)
{
	int	rot;

	rot = 15;
	if (grid.length >= 100 || grid.width >= 100)
		rot += 10;
	if (grid.length >= 200 || grid.width >= 200)
		rot += 10;
	if (grid.length >= 500 || grid.width >= 500)
		rot += 10;
	return (rot);
}

/*Initialize values of plane structure*/
t_plane	*init_plane(t_grid grid, t_coord **coord)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (plane == NULL)
	{
		coord_clear(coord);
		exit (EXIT_FAILURE);
	}
	plane->v_rot = 45;
	plane->h_rot = init_horizontal_rotation(grid);
	init_vect_x(plane, coord);
	init_vect_y(plane, coord);
	init_vect_z(plane, coord);
	plane->width = init_plane_width(grid, plane);
	plane->height = init_plane_height(grid, plane);
	plane->h_marg = init_horizontal_margin(grid, *plane);
	plane->v_marg = init_vertical_margin(grid, *plane);
	plane->o = init_pixel();
	if (plane->o == NULL)
	{
		free_plane(plane);
		coord_clear(coord);
		exit (EXIT_FAILURE);
	}
	return (plane);
}
