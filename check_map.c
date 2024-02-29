/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:54:34 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/23 15:46:30 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_and_exit(char **line, char *str, int fd)
{
	ft_putstr_fd("Error in map format\n", 2);
	free_tab(line);
	free(str);
	close (fd);
	exit (1);
}

static int	check_color(char *color, char **line, char *str, int fd)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (!ft_ischarset(color[i], "0123456789abcdefABCDEF"))
			free_and_exit(line, str, fd);
		i++;
	}
	if (i < 2 || i > 6 || color[i] != '\0')
		free_and_exit(line, str, fd);
	return (i);
}

static void	check_elem(char **line, int i, char *str, int fd)
{
	int	j;

	j = 0;
	if (line[i][j] == '+' || line[i][j] == '-')
		j++;
	if (!ft_isdigit(line[i][j]))
		free_and_exit(line, str, fd);
	while (ft_isdigit(line[i][j]))
		j++;
	if (ft_strncmp(line[i] + j, ",0x", 3) == 0)
	{
		j += 3;
		j += check_color(line[i] + j, line, str, fd);
	}
	if (line[i][j] != '\0')
		free_and_exit(line, str, fd);
}

static void	check_line(char *str, int fd)
{
	char		**line;
	int			i;
	static int	elems_per_line;

	line = ft_split(str, " \n");
	if (line == NULL)
		free_and_exit(line, str, fd);
	i = 0;
	while (line[i])
	{
		check_elem(line, i, str, fd);
		i++;
	}
	if (elems_per_line == 0)
		elems_per_line = i;
	else if (elems_per_line != i)
		free_and_exit(line, str, fd);
	free_tab(line);
}

void	check_map(char *file)
{
	int		fd;
	char	*str;

	check_file_ext(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit (1);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		check_line(str, fd);
		free(str);
	}
	free(str);
	close (fd);
}
