/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:58:57 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/15 15:41:07 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Allocate memory for X vector and for pixel structure in it
Initialize values of vector structure in plane
*/
static void	init_vect_x(t_plane *plane, t_coord **coord)
{
	int	dist_to_h_axis;

	plane->x = (t_vect *)malloc(sizeof(t_vect));
	if (plane->x == NULL)
	{
		free_plane(plane);
		coord_clear(coord);
		exit (EXIT_FAILURE);
	}
	plane->x->scale = 100;
	plane->x->abs = (int)(cos((90 - plane->v_rot) * M_PI / 180) * plane->x->scale);
	dist_to_h_axis = (int)sqrt(pow(plane->x->scale, 2) - pow(plane->x->abs, 2));
	plane->x->ord = (int)(sin((plane->h_rot) * M_PI / 180) * dist_to_h_axis);
	plane->x->in_win = init_pixel(plane, coord);
}

/*
Allocate memory for Y vector and for pixel structure in it
Initialize values of vector structure in plane
*/
static void	init_vect_y(t_plane *plane, t_coord **coord)
{
	int	dist_to_h_axis;

	plane->y = (t_vect *)malloc(sizeof(t_vect));
	if (plane->y == NULL)
	{
		free_plane(plane);
		coord_clear(coord);
		exit (EXIT_FAILURE);
	}
	plane->y->scale = 100;
	plane->y->abs = (int)(cos((plane->v_rot) * M_PI / 180) * plane->y->scale);
	dist_to_h_axis = (int)sqrt(pow(plane->y->scale, 2) - pow(plane->y->abs, 2));
	plane->y->ord = (int)((sin(plane->h_rot * M_PI / 180) * dist_to_h_axis) * (-1));
	plane->y->in_win = init_pixel(plane, coord);
}

/*
Allocate memory for Z vector and for pixel structure in it
Initialize values of vector structure in plane
*/
static void	init_vect_z(t_plane *plane, t_coord **coord)
{
	plane->z = (t_vect *)malloc(sizeof(t_vect));
	if (plane->z == NULL)
	{
		free_plane(plane);
		coord_clear(coord);
		exit (EXIT_FAILURE);
	}
	plane->z->scale = 100;
	plane->z->abs = 0;
	plane->z->ord = (int)(cos(plane->h_rot * M_PI / 180) * plane->z->scale);
	plane->z->in_win = init_pixel(plane, coord);
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
void	init_plane(t_grid grid, t_plane *plane, t_coord **coord)
{
	ft_printf("grid.name = %s\n", grid.name);
	ft_printf("grid.fd = %d\n", grid.fd);
	ft_printf("grid.width = %d\n", grid.width);
	ft_printf("grid.length = %d\n", grid.length);
	ft_printf("grid.deepest = %d\n", grid.deepest);
	ft_printf("grid.highest = %d\n", grid.highest);
	plane->v_rot = 45;
	plane->h_rot = init_horizontal_rotation(grid);
	init_vect_x(plane, coord);
	init_vect_y(plane, coord);
	init_vect_z(plane, coord);
	plane->width = init_plane_width(grid, plane);
	plane->height = init_plane_height(grid, plane);
	plane->h_marg = init_horizontal_margin(grid, *plane);
	plane->v_marg = init_vertical_margin(grid, *plane);
	plane->o = init_pixel(plane, coord);
	ft_printf("plane->v_rot = %?37d, plane->h_rot = %?37d\n", plane->v_rot, plane->h_rot);
	ft_printf("plane->x->scale = %?37d, plane->y->scale = %?37d, plane->z->scale = %?37d\n", plane->x->scale, plane->y->scale, plane->z->scale);
}
