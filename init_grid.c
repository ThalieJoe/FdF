/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:31:58 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/14 11:32:33 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	init_grid(char *file, t_grid *grid, int fd)
{
	grid->name = get_file_name(file);
	grid->fd = fd;
	grid->length = 0;
	grid->width = 0;
	grid->deepest = 0;
	grid->highest = 0;
}
