/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:32:30 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/16 15:26:58 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	data_init(t_data *pixel)
{
	pixel->prev_x = 0;
	pixel->prev_y = 0;
	pixel->cur_x = 0;
	pixel->cur_y = 0;
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
		free(str);
		free_tab(line);
	}

}
