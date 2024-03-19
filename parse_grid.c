/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:03:52 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 13:53:48 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_file_ext(char *str)
{
	size_t	len;
	char	*trim;

	trim = ft_strtrim(str, "\t\n\v\f ");
	len = ft_strlen(trim);
	if (ft_strcmp(trim + (len - 4), ".fdf") != 0)
	{
		free (trim);
		ft_putendl_fd("Usage: <file>.fdf", 2);
		exit (EXIT_FAILURE);
	}
	free (trim);
}

static char	*get_file_name(char *file)
{
	int	len;

	len = ft_strlen(file);
	file[len - 4] = '\0';
	while (len)
	{
		if (file[len] == '/')
			return (file + (len + 1));
		len--;
	}
	return (file);
}

static void	init_grid(char *file, t_grid *grid, int fd)
{
	grid->name = get_file_name(file);
	grid->fd = fd;
	grid->length = 0;
	grid->width = 0;
	grid->deepest = 0;
	grid->highest = 0;
}

void	parse_grid(char *file, t_map *map)
{
	int		fd;
	char	*line;

	check_file_ext(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit (EXIT_FAILURE);
	init_grid(file, &(map->grid), fd);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->grid.width++;
		parse_line(line, map);
		free (line);
	}
	if (map->grid.width == 0)
	{
		ft_putendl_fd("Empty file", 2);
		exit (EXIT_FAILURE);
	}
	close(fd);
}
