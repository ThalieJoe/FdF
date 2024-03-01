/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:54:34 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/23 12:24:51 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_and_exit(char **line)
{
	ft_putstr_fd("WRONG FORMAT IN FILE", 2);
	free_tab(line);
	exit (1);
}

static int	check_color(char *color, char **line)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (!ft_ischarset(color[i], "0123456789abcdefABCDEF"))
			free_and_exit(line);
		i++;
	}
	if (i < 2 || i > 6 || color[i] != '\0')
		free_and_exit(line);
	return (i);
}

static void	check_elem(char **line, int i)
{
	int	j;
	int	first_digit;

	j = 0;
	first_digit = 0;
	if (line[i][j] == '+' || line[i][j] == '-')
		j++;
	if (!ft_isdigit(line[i][j]))
		free_and_exit(line);
	while (ft_isdigit(line[i][j]))
		j++;
	if (ft_strncmp(line[i] + j, ",0x", 3) == 0)
	{
		j += 3;
		j += check_color(line[i] + j, line);
	}
	if (line[i][j] != '\0')
		free_and_exit(line);
}

static void	parse_line(char **line, t_file *infos)
{
	int	i;

	i = 0;
	while (line[i])
	{
		check_elem(line, i);
		if (ft_atoi(line[i]) > infos->height)
			infos->height = ft_atoi(line[i]);
		if (ft_atoi(line[i]) < infos->depth)
			infos->depth = ft_atoi(line[i]);
		i++;
	}
	if (infos->elems == 0)
		infos->elems = i;
	else if (infos->elems != i)
		free_and_exit(line);
}

void	parse_file(char *file, t_file *infos)
{
	int		fd;
	char	**line;

	check_file_ext(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit (1);
	infos->name = file;
	infos_init(infos);
	while (1)
	{
		line = ft_split(get_next_line(fd), " \n");
		if (line == NULL)
			break ;
		infos->lines++;
		parse_line(line, infos);
		free_tab(line);
	}
}
