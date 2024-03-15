/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:34:02 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/15 14:47:07 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "time.h"

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
// 		if (coord->head)
// 			ft_printf("coord->head->x = %?34d, coord->head->y = %?34d\n", coord->head->x, coord->head->y);
// 		coord = coord->next;
// 	}
// }

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

void	parse_line(char *line, t_grid *grid, t_coord **coord)
{
	char	**elem;
	clock_t	start, end;
	double	cpu_time_used;

	elem = ft_split(line, " \n");
	if (elem == NULL)
		free_and_exit(grid->fd, coord, elem, line);
	check_elem(elem, grid, coord, line);
	get_grid_len(elem, grid, coord, line);
	get_extremes(elem, grid);
	start = clock();
	add_to_coord(elem, coord, grid, line);
	end = clock();
	cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
	printf("add_to_coord %f seconds\n", cpu_time_used);
	free_tab(elem);
}
