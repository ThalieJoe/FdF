/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:56:13 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/15 15:28:57 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	open_window(t_xvar **connect)
{
	*connect = mlx_init();
	if (*connect == NULL)
		exit (1);
	(*connect)->win_list = mlx_new_window(*connect, 990, 540, "New");
	if ((*connect)->win_list == NULL)
	{
		mlx_destroy_display(*connect);
		free(*connect);
		exit (1);
	}
}

void 	close_window(t_xvar **connect)
{
	mlx_clear_window(*connect, (*connect)->win_list);
	mlx_destroy_window(*connect, (*connect)->win_list);
	mlx_destroy_display(*connect);
	free(*connect);
}

int	handle_input(int keysym, t_xvar *connect)
{
	if (keysym == XK_Escape)
	{
		ft_printf("Escape key %?36d has been pressed\n", keysym);
		close_window(&connect);
		exit (1);
	}
	ft_printf("Key %?35d has been pressed\n", keysym);
	return (0);
}

void	put_pixel_in_image(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * img->size_line + x * (img->bpp / 8);
	dst = img->data + offset;
	*(unsigned int *)dst = color;
}

int	main(void)
{
	t_xvar	*connect;
	t_img	*img;
	int		w;
	int		h;

	w = 225;
	h = 225;
	connect = NULL;
	img = NULL;
	open_window(&connect);
	mlx_key_hook(connect->win_list, &handle_input, connect);
	//mlx_pixel_put(connect, connect->win_list, 100, 100, 0x00FFFF00);
	img = mlx_new_image(connect, 990, 540);
	//img = mlx_xpm_file_to_image(connect, "./images/tyrano.xpm", &w, &h);
	if (img == NULL)
	{
		close_window(&connect);
		return (1);
	}
	img->data = mlx_get_data_addr(img, &img->bpp, &img->size_line, &img->image->byte_order);
	put_pixel_in_image(img, 495, 270, 0xFFFF00);
	mlx_put_image_to_window(connect, connect->win_list, img, 20, 20);
	mlx_loop(connect);
	free(img);
	close_window(&connect);
	return (0);
}
