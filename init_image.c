/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:31:01 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/16 16:02:24 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key_input(int keysym, t_xvar **connect)
{
	if (keysym == XK_Escape)
	{
		ft_printf("key pressed is %?32d\n", keysym);
		close_window(connect);
		return (0);
	}
	ft_printf("key pressed is %?33d\n", keysym);
	return (0);
}

t_img	*init_image(t_xvar **connect)
{
	t_img	*img;

	open_window(connect);
	img = mlx_new_image(*connect, 200, 200);
	if (!img)
	{
		close_window(connect);
		mlx_destroy_display(*connect);
		free(*connect);
		exit (1);
	}
	img->data = mlx_get_data_addr(img, &img->bpp, &img->size_line, &img->image->byte_order);
	mlx_hook((*connect)->win_list, 17, 1L<<17, &close_window, connect);
	mlx_key_hook((*connect)->win_list, &handle_key_input, connect);
	return (img);
}
