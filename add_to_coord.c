/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:25:40 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/12 16:38:41 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	print_coord(t_coord *coord)
// {
// 	while (coord)
// 	{
// 		ft_printf("%?32s %?92s\n", "NEW", "NODE :");
// 		ft_printf("coord->x = %d\n", coord->x);
// 		ft_printf("coord->y = %d\n", coord->y);
// 		ft_printf("coord->z = %d\n", coord->z);
// 		ft_printf("coord->px->abs = %d\n", coord->px->abs);
// 		ft_printf("coord->px->ord = %d\n", coord->px->ord);
// 		printf("coord->color = %ld\n", coord->color);
// 		if (coord->prev_x)
// 			ft_printf("coord->prev_x->x = %?33d, coord->prev_x->y = %?33d\n", coord->prev_x->x, coord->prev_x->y);
// 		if (coord->prev_y)
// 			ft_printf("coord->prev_y->x = %?34d, coord->prev_y->y = %?34d\n", coord->prev_y->x, coord->prev_y->y);
// 		coord = coord->next;
// 	}
// }

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

static void	find_coord_previous(t_coord *coord, t_coord *new)
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
		free_plane(&plane);
		clean_and_exit(connect, 1);
	}
	new->x = val[0];
	new->y = val[1];
	new->z = val[2];
	new->px = init_pixel(&plane);
	new->px->abs = plane.o->abs + plane.x->abs * new->x + plane.y->abs * new->y + plane.z->abs * new->z;
	new->px->ord = plane.o->ord - plane.x->ord * new->x - plane.y->ord * new->y - plane.z->ord * new->z;
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
		find_coord_previous(*coord, new);
		coord_add_back(coord, new);
		i++;
	}
	y++;
	// print_coord(*coord);
}
