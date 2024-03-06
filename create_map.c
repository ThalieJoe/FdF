/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:32:30 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/06 14:48:26 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_map(t_xvar *connect, t_map map, t_plane plane)
{
	int		fd;
	char	*line;
	char	**elem;
	t_coord *coord;

	fd = open(map.name, O_RDONLY);
	if (fd == -1)
		return ;
	coord = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		elem = ft_split(line, " \n");
		add_to_coord(connect, elem, &coord, plane);
		free_tab(elem);
		free(line);
	}
	draw(connect, coord);
	coord_clear(&coord);
}
