/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:58:57 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/12 17:01:58 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Allocate memory for X vector and for pixel structure in it
Initialize values of vector structure in plane
*/
static void	init_vect_x(t_plane *plane)
{
	plane->x = (t_vect *)malloc(sizeof(t_vect));
	if (plane->x == NULL)
	{
		free_plane(plane);
		exit (EXIT_FAILURE);
	}
	plane->x->scale = 100;
	plane->x->abs = (int)(cos(45 * M_PI / 180) * plane->x->scale);
	plane->x->ord = (int)(cos(75 * M_PI / 180) * plane->x->scale);
	plane->x->in_win = init_pixel(plane);
}

/*
Allocate memory for Y vector and for pixel structure in it
Initialize values of vector structure in plane
*/
static void	init_vect_y(t_plane *plane)
{
	plane->y = (t_vect *)malloc(sizeof(t_vect));
	if (plane->y == NULL)
	{
		free_plane(plane);
		exit (EXIT_FAILURE);
	}
	plane->y->scale = 100;
	plane->y->abs = (int)(cos(45 * M_PI / 180) * plane->y->scale);
	plane->y->ord = (int)((cos(75 * M_PI / 180) * plane->y->scale) * (-1));
	plane->y->in_win = init_pixel(plane);
}

/*
Allocate memory for Z vector and for pixel structure in it
Initialize values of vector structure in plane
*/
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
	plane->z->ord = (int)(cos(15 * M_PI / 180) * plane->y->scale);
	plane->z->in_win = init_pixel(plane);
}

/*Initialize values of plane structure*/
void	init_plane(t_grid grid, t_plane *plane)
{
	init_vect_x(plane);
	init_vect_y(plane);
	init_vect_z(plane);
	plane->width = init_plane_width(grid, plane);
	plane->height = init_plane_height(grid, plane);
	plane->h_marg = init_horizontal_margin(*plane);
	plane->v_marg = init_vertical_margin(*plane);
	plane->o = init_pixel(plane);
}
