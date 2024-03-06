/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:44:38 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/22 15:33:20 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	*find_prev_x(t_coord *coord, int x, int y)
{
	if (!coord || x == 0)
		return (NULL);
	while (coord)
	{
		if (coord->x == x - 1 && coord->y == y)
			return (coord);
		coord = coord->next;
	}
	return (NULL);
}

static t_coord	*find_prev_y(t_coord *coord, int x, int y)
{
	if (!coord || y == 0)
		return (NULL);
	while (coord)
	{
		if (coord->x == x && coord->y == y - 1)
			return (coord);
		coord = coord->next;
	}
	return (NULL);
}

static t_coord	*coordnew(t_coord *coord, int x, int y, int z)
{
	t_coord	*new_coord;

	new_coord = (t_coord *)malloc(sizeof(t_coord));
	if (new_coord == NULL)
		return (NULL);
	new_coord->x = x;
	new_coord->y = y;
	new_coord->z = z;
	new_coord->prev_x = find_prev_x(coord, x, y);
	new_coord->prev_y = find_prev_y(coord, x, y);
	new_coord->next = NULL;
	return (new_coord);
}

static void	coord_addback(t_coord **coord, t_coord *new)
{
	t_coord	*last;
	t_coord	*tmp;

	if (!coord || !new)
		return ;
	if (*coord == NULL)
	{
		*coord = new;
		return ;
	}
	tmp = *coord;
	while (tmp->next)
		tmp = tmp->next;
	last = tmp;
	last->next = new;
}

void	add_coords(t_coord **coord, char **line, int y)
{
	int		i;
	t_coord	*new;

	i = 0;
	while (line[i])
	{
		new = coordnew(*coord, i, y, ft_atoi(line[i]));
		coord_addback(coord, new);
		i++;
	}
}
