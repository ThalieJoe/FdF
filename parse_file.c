/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:54:34 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/20 10:37:34 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	infos_init(t_file *infos)
{
	infos->lines = 0;
	infos->elems = 0;
	infos->size = 0;
	infos->height = 0;
	infos->depth = 0;
}

int	check_color(char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (!ft_ischarset(color[i], "0123456789abcdefABCDEF"))
			exit (1);
		// ft_printf("color[%d] = %c\n", i, color[i]);
		i++;
	}
	if (i < 2 || i > 6 || color[i] != '\0')
		exit (1);
	return (i);
}

void	check_coordinate(char *coordinate)
{
	int	i;
	int	first_digit;

	i = 0;
	first_digit = 0;
	if (coordinate[i] == '+' || coordinate[i] == '-')
		i++;
	if (!ft_isdigit(coordinate[i]))
		exit (1);
	while (ft_isdigit(coordinate[i]))
		i++;
	if (ft_strncmp(coordinate + i, ",0x", 3) == 0)
	{
		i += 3;
		i += check_color(coordinate + i);
	}
	if (coordinate[i] != '\0')
		exit (1);
	// if (coordinate[i] == '\0')
	// 	exit (1);
	// while (coordinate[i])
	// {
	// 	if (!ft_isdigit(coordinate[i]) && first_digit && coordinate[i] != ',')
	// 		exit (1);
	// 	if (!ft_isdigit(coordinate[i]) && !first_digit)
	// 		exit (1);
	// 	first_digit = 1;
	// 	ft_printf("coordinate[%d] = %c\n", i, coordinate[i]);
	// 	if (ft_isdigit(coordinate[i]))
	// 		i++;
	// 	else
	// 		break ;
	// }
	// if (ft_strncmp(coordinate + i, ",0x", 3) == 0)
	// {
	// 	i += 3;
	// 	check_color(coordinate + i);
	// }
	// else if (coordinate[i] != '\0')
	// 	exit (1);
}

void	parse_line(char **line, t_file *infos)
{
	int	i;

	i = 0;
	while (line[i])
	{
		check_coordinate(line[i]);
		ft_printf("InHEREs = %d\n", infos->elems);
		if (ft_atoi(line[i]) > infos->height)
			infos->height = ft_atoi(line[i]);
		if (ft_atoi(line[i]) < infos->depth)
			infos->depth = ft_atoi(line[i]);
		i++;
	}
	if (infos->elems == 0)
		infos->elems = i;
	else if (infos->elems != i)
		exit (1);
	ft_printf("Infos elems = %d\n", infos->elems);
}

void	parse_file(char *file, t_file *infos)
{
	int		fd;
	char	**line;

	fd = open(file, O_RDONLY);
	ft_printf("fd = %d\n", fd);
	if (fd == -1)
		exit (1);
	infos_init(infos);
	while (1)
	{
		line = ft_split(get_next_line(fd), " \n");
		if (line == NULL)
			break ;
		infos->lines++;
		parse_line(line, infos);
		ft_printf("in check coord infos->lines = %d, infos->elems = %d, infos->size = %d, infos->height = %d, , infos->depth = %d\n", infos->lines, infos->elems, infos->size, infos->height, infos->depth);
	}
	infos->size = infos->height - infos->depth;
}
