/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:02:51 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/19 15:03:45 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_img **img, char **line, t_data *pixel)
{
	int	i;

	i = 0;
	while (line[i])
	{
		pixel->cur_z = ft_atoi(line[i]);
		// ft_printf("when line[%d] = %s, pixel->x = %d, pixel->y = %d, pixel->z = %d\n", i, line[i], pixel->cur_x, pixel->cur_y, pixel->cur_z);
		put_pixels_in_image_from_above(*img, pixel);
		pixel->cur_x += 50;
		i++;
	}
}
