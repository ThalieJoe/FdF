/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:25:40 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/06 15:21:53 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_coord(t_coord *coord)
{
	while (coord)
	{
		ft_printf("%?32s %?92s\n", "NEW", "NODE :");
		ft_printf("coord->x = %d\n", coord->x);
		ft_printf("coord->y = %d\n", coord->y);
		ft_printf("coord->z = %d\n", coord->z);
		ft_printf("coord->abs = %d\n", coord->abs);
		ft_printf("coord->ord = %d\n", coord->ord);
		printf("coord->color = %ld\n", coord->color);
		if (coord->prev_x)
			ft_printf("coord->prev_x->x = %?33d, coord->prev_x->y = %?33d\n", coord->prev_x->x, coord->prev_x->y);
		if (coord->prev_y)
			ft_printf("coord->prev_y->x = %?34d, coord->prev_y->y = %?34d\n", coord->prev_y->x, coord->prev_y->y);
		coord = coord->next;
	}
}

void	coord_clear(t_coord **coord)
{
	t_coord	*next;

	if (coord == NULL)
		return ;
	while (*coord)
	{
		next = (*coord)->next;
		free(*coord);
		*coord = next;
	}
	*coord = NULL;
}

static void	find_color(t_coord *new, char *elem)
{
	char	*color;
	char	*low_color;
	int		i;

	i = 0;
	color = NULL;
	while (elem[i] && elem[i] != ',')
		i++;
	if (elem[i] == '\0')
		new->color = 16777215;
	else
	{
		i += 3;
		low_color = ft_strtolower(elem + i);
		color = ft_convert_base(low_color, "0123456789abcdef", "0123456789");
		free(low_color);
		new->color = ft_atol(color);
		free(color);
	}
}

static void	find_coord_prev_xy(t_coord *coord, t_coord *new)
{
	t_coord	*cur;

	if (new->x == 0)
		new->prev_x = NULL;
	if (new->y == 0)
		new->prev_y = NULL;
	cur = coord;
	while (cur)
	{
		if (cur->x == new->x - 1 && cur->y == new->y)
			new->prev_x = cur;
		if (cur->y == new->y - 1 && cur->x == new->x)
			new->prev_y = cur;
		cur = cur->next;
	}
}

static void	coord_add_back(t_coord **coord, t_coord *new)
{
	t_coord	*last;

	if (coord == NULL)
		return ;
	if (*coord == NULL)
	{
		*coord = new;
		return ;
	}
	last = *coord;
	while (last->next)
		last = last->next;
	last->next = new;
}

static t_coord	*coord_new(t_xvar *connect, int *val, t_plane plane, t_coord **coord)
{
	t_coord	*new;

	new = (t_coord *)malloc(sizeof(t_coord));
	if (new == NULL)
	{
		coord_clear(coord);
		clean_and_exit(connect, &plane, 1);
	}
	new->x = val[0];
	new->y = val[1];
	new->z = val[2];
	new->abs = plane.xorigin_in_win + plane.view->x_vect_abs * new->x + plane.view->y_vect_abs * new->y + plane.view->z_vect_abs * new->z;
	new->ord = plane.yorigin_in_win - plane.view->x_vect_ord * new->x - plane.view->y_vect_ord * new->y - plane.view->z_vect_ord * new->z;
	new->next = NULL;
	return (new);
}

void	add_to_coord(t_xvar *connect, char **elem, t_coord **coord, t_plane plane)
{
	int			i;
	int			z;
	int			val[3];
	t_coord		*new;
	static int	y = 0;

	i = 0;
	while (elem[i])
	{
		z = ft_atoi(elem[i]);
		val[0] = i;
		val[1] = y;
		val[2] = z;
		new = coord_new(connect, val, plane, coord);
		find_color(new, elem[i]);
		find_coord_prev_xy(*coord, new);
		coord_add_back(coord, new);
		i++;
	}
	y++;
	// print_coord(*coord);
}
