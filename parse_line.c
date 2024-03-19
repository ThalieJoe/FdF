/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:34:02 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 13:42:59 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_color(char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (!ft_ischarset(color[i], "0123456789abcdefABCDEF"))
			return (0);
		i++;
	}
	if (i < 2 || i > 6 || color[i] != '\0')
		return (0);
	return (i);
}

static void	check_elem(char **elem, t_grid *grid, t_coord **coord, char *line)
{
	int	i;
	int	j;

	i = 0;
	while (elem[i])
	{
		j = 0;
		if (elem[i][j] == '+' || elem[i][j] == '-')
			j++;
		if (!ft_isdigit(elem[i][j]))
			free_and_exit(grid->fd, coord, elem, line);
		while (ft_isdigit(elem[i][j]))
			j++;
		if (ft_strncmp(elem[i] + j, ",0x", 3) == 0)
		{
			j += 3;
			if (!check_color(elem[i] + j))
				free_and_exit(grid->fd, coord, elem, line);
			else
				j += check_color(elem[i] + j);
		}
		if (elem[i][j] != '\0')
			free_and_exit(grid->fd, coord, elem, line);
		i++;
	}
}

static void	get_grid_len(char **elem, t_grid *grid, t_coord **coord, char *line)
{
	int		i;

	i = 0;
	while (elem[i])
		i++;
	if (grid->length == 0)
		grid->length = i;
	else
	{
		if (i != grid->length)
			free_and_exit(grid->fd, coord, elem, line);
	}
}

static void	get_extremes(char **elem, t_grid *grid)
{
	int		i;

	i = 0;
	while (elem[i])
	{
		if (ft_atoi(elem[i]) < grid->deepest)
			grid->deepest = ft_atoi(elem[i]);
		if (ft_atoi(elem[i]) > grid->highest)
			grid->highest = ft_atoi(elem[i]);
		i++;
	}
}

void	parse_line(char *line, t_map *map)
{
	char	**elem;

	elem = ft_split(line, " \n");
	if (elem == NULL)
		free_and_exit(map->grid.fd, &(map->coord), elem, line);
	check_elem(elem, &(map->grid), &(map->coord), line);
	get_grid_len(elem, &(map->grid), &(map->coord), line);
	get_extremes(elem, &(map->grid));
	add_to_coord(elem, map, line);
	free_tab(elem);
}
