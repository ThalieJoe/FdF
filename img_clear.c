/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:33:53 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 14:23:05 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_clear(t_xvar *connect, t_image **image)
{
	t_image	*cur;
	t_image	*next;

	if (connect == NULL || image == NULL || *image == NULL)
		return ;
	cur = *image;
	while (cur)
	{
		next = cur->next;
		mlx_destroy_image(connect, cur->img);
		free(cur);
		cur = next;
	}
	*image = NULL;
}
