/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:03:52 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/26 12:40:08 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_extremes(t_map *map, char *str)
{
	char	**line;
	int		i;

	if (str == NULL)
		return ;
	line = ft_split(str, " \n");
	i = 0;
	while (line[i])
	{
		if (ft_atoi(line[i]) < map->deepest)
			map->deepest = ft_atoi(line[i]);
		if (ft_atoi(line[i]) > map->highest)
			map->highest = ft_atoi(line[i]);
		i++;
	}
	free_tab(line);
}

static int	grid_length(char *str)
{
	char	**line;
	int		i;

	line = ft_split(str, " \n");
	i = 0;
	while (line[i])
		i++;
	free_tab(line);
	return (i);
}

void	parse_map(char *file, t_map *map)
{
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit (1);
	map->name = file;
	map->deepest = 0;
	map->highest = 0;
	str = get_next_line(fd);
	get_extremes(map, str);
	map->grid_width = 0;
	map->grid_length = grid_length(str);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		get_extremes(map, str);
		map->grid_width++;
		free(str);
	}
	close (fd);
}
