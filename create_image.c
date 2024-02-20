/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:32:30 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/19 11:11:28 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	data_init(t_data *pixel)
{
	pixel->prev_x = 0;
	pixel->prev_y = 0;
	pixel->prev_z_in_x = 0;
	pixel->prev_z_in_y = NULL;
	pixel->cur_x = 0;
	pixel->cur_y = 0;
	pixel->cur_z = 0;
}

void	save_coordinate_z(char **line, t_data *pixel)
{
	int		i;

	i = 0;
	if (line == NULL)
		return ;
	while (line[i])
		i++;
	pixel->prev_z_in_y = (char **)malloc(sizeof(char *) * (i + 1));
	if (!pixel->prev_z_in_y)
		return ;
	i = 0;
	while (line[i])
	{
		pixel->prev_z_in_y[i] = ft_itoa(ft_atoi(line[i]));
		i++;
	}
	pixel->prev_z_in_y[i] = NULL;
}

void	create_image(t_xvar **connect, t_img **img, char *file)
{
	int		fd;
	char	*str;
	char	**line;
	t_data	pixel;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close_window(connect);
		clean_and_exit(connect, img);
	}
	data_init(&pixel);
	line = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break;
		line = ft_split(str, " ");
		draw(img, line, &pixel);
		pixel.cur_x = 0;
		pixel.prev_x = 0;
		pixel.prev_y = pixel.cur_y;
		pixel.cur_y += 10;
		free_tab(pixel.prev_z_in_y);
		save_coordinate_z(line, &pixel);
		free(str);
		free_tab(line);
	}
	free_tab(pixel.prev_z_in_y);
}
