/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:20:28 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 16:05:43 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	imgadd_front(t_image **image, t_image *new)
{
	if (image == NULL || new == NULL)
		return ;
	new->next = *image;
	*image = new;
}

void	add_new_image(t_map *map, int width, int height)
{
	t_img	*img;
	t_image	*new;

	img = (t_img *)mlx_new_image(map->connect, width, height);
	if (img == NULL)
	{
		clean_all(map);
		exit (EXIT_FAILURE);
	}
	new = (t_image *)ft_lstnew(img);
	if (new == NULL)
	{
		clean_all(map);
		exit (EXIT_FAILURE);
	}
	imgadd_front(&(map->image), new);
}
