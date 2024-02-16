/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_v3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:43:08 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/15 15:28:53 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	open_window(t_xvar **connect)
{
	*connect = mlx_init();
	if (*connect == NULL)
		exit (1);
	(*connect)->win_list = mlx_new_window(*connect, 990, 540, "sarah's window");
	if ((*connect)->win_list == NULL)
	{
		mlx_destroy_display(*connect);
		free(*connect);
		exit (1);
	}
}

int	close_window(t_xvar **connect)
{
	mlx_loop_end(*connect);
	mlx_destroy_window(*connect, (*connect)->win_list);
	return (0);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (x * (img->bpp / 8) + y * img->size_line);
	dst = img->data + offset;
	*(int *)dst = color;
}

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

int	main(void)
{
	t_xvar	*connect;
	t_img	*img;
	int		win_x_return;
	int		win_y_return;

	win_x_return = 60;
	win_y_return = 50;
	open_window(&connect);
	img = mlx_new_image(connect, 200, 200);
	if (!img)
	{
		close_window(&connect);
		mlx_destroy_display(connect);
		free(connect);
		return (1);
	}
	img->data = mlx_get_data_addr(img, &img->bpp, &img->size_line, &img->image->byte_order);
	my_pixel_put(img, 20, 20, 0x00FFFF00);
	my_pixel_put(img, 80, 80, 0x0000FFFF);
	my_pixel_put(img, 82, 82, 0xFFFF);
	mlx_put_image_to_window(connect, connect->win_list, img, 50, 50);
	mlx_hook(connect->win_list, 17, 1L<<17, &close_window, &connect);
	mlx_key_hook(connect->win_list, &handle_key_input, &connect);
	// mlx_mouse_hook(connect->win_list, &handle_click_input, &connect);
	// ret = mlx_mouse_get_pos(connect, connect->win_list, &win_x_return, &win_y_return);
	// ft_printf("My mlx_mouse_get_pos = %d\n", ret);
	mlx_loop(connect);
	mlx_destroy_image(connect, img);
	mlx_destroy_display(connect);
	free(connect);
	return (0);
}
