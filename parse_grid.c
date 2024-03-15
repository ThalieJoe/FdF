/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:03:52 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/15 16:09:11 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_grid(char *file, t_grid *grid, t_coord **coord)
{
	int		fd;
	char	*line;
	int		it;

	it = 1;
	check_file_ext(file);
	ft_printf("ext checked\n");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit (1);
	ft_printf("fd opened\n");
	init_grid(file, grid, fd);
	ft_printf("grid initiated\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_printf("line number %d got\n", it);
		it++;
		grid->width++;
		parse_line(line, grid, coord);
		free (line);
	}
	if (grid->width == 0)
		exit (1);
	close(fd);
}
