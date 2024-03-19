/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:25:40 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 14:07:59 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static void	find_coord_previous(t_coord *new)
{
	t_coord	*cur;

	if (new->x)
		new->prev_x = new->prev;
	if (new->y)
	{
		cur = new;
		while (cur->y != ((new->y) - 1) || cur->x != new->x)
			cur = cur->prev;
		new->prev_y = cur;
	}
}

static t_coord	*coord_add_back(t_coord **coord, t_coord *new)
{
	if (coord == NULL)
		return (NULL);
	if (*coord == NULL)
	{
		*coord = new;
		return (new);
	}
	(*coord)->head->next = new;
	new->prev = (*coord)->head;
	return (new);
}

static t_coord	*coord_new(int *val)
{
	t_coord	*new;

	new = (t_coord *)malloc(sizeof(t_coord));
	if (new == NULL)
		return (NULL);
	new->x = val[0];
	new->y = val[1];
	new->z = val[2];
	new->px = init_pixel();
	if (new->px == NULL)
		return (NULL);
	new->prev_x = NULL;
	new->prev_y = NULL;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	add_to_coord(char **elem, t_map *map, char *line)
{
	int			i;
	int			val[3];
	t_coord		*new;
	static int	y = 0;

	i = 0;
	while (elem[i])
	{
		val[0] = i;
		val[1] = y;
		val[2] = ft_atoi(elem[i]);
		new = coord_new(val);
		if (new == NULL)
			free_and_exit(map->grid.fd, &(map->coord), elem, line);
		find_color(new, elem[i]);
		map->coord->head = coord_add_back(&(map->coord), new);
		find_coord_previous(new);
		i++;
	}
	y++;
}
