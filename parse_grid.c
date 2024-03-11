/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:03:52 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/11 16:17:13 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_extremes(t_grid *grid, char *str)
{
	char	**line;
	int		i;

	if (str == NULL)
		return ;
	line = ft_split(str, " \n");
	i = 0;
	while (line[i])
	{
		if (ft_atoi(line[i]) < grid->deepest)
			grid->deepest = ft_atoi(line[i]);
		if (ft_atoi(line[i]) > grid->highest)
			grid->highest = ft_atoi(line[i]);
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

void	parse_grid(char *file, t_grid *grid)
{
	int		fd;
	char	*str;

	check_grid(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit (1);
	grid->name = file;
	grid->deepest = 0;
	grid->highest = 0;
	str = get_next_line(fd);
	get_extremes(grid, str);
	grid->width = 0;
	grid->length = grid_length(str);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		get_extremes(grid, str);
		grid->width++;
		free(str);
	}
	close (fd);
}
