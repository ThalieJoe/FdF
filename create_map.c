/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:32:30 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/12 17:30:44 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_horizontal_line(t_xvar *connect, int cur_abs, int prev_abs, int ord)
{
	while (prev_abs < cur_abs)
	{
		mlx_pixel_put(connect, connect->win_list, prev_abs, ord, 0xFFFFFF);
		prev_abs++;
	}
}

static void	draw_vertical_line(t_xvar *connect, t_plane plane)
{
	int	origin;

	origin = 0;
	while (origin < plane.height + plane.v_marg)
	{
		mlx_pixel_put(connect, connect->win_list, ((plane.width + (plane.h_marg * 2)) / 2), origin, 0xFFFF00);
		origin++;
	}
}

void	create_map(t_xvar *connect, t_grid grid, t_plane plane)
{
	int		fd;
	char	*line;
	char	**elem;
	t_coord *coord;

	fd = open(grid.name, O_RDONLY);
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
	close(fd);
	draw_horizontal_line(connect, plane.width, plane.h_marg, plane.o->ord);
	draw_vertical_line(connect, plane);
	draw(connect, coord);
	coord_clear(&coord);
}
