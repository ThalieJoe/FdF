/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_v1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:29:50 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/14 17:18:50 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#ifndef WIDTH
# define WIDTH 990
#endif
#ifndef HEIGHT
# define HEIGHT 540
#endif

#define SIDE_LEN 990

typedef unsigned char byte;

typedef struct s_data
{
	t_xvar	*connect;
	void	*window;
	t_img	img;
}			t_data;

int	encode_rgb(byte red, byte green, byte blue)
{
	return (red << 16 | green << 8 | blue);
}

void	color_screen(t_data *mlx, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < SIDE_LEN)
	{
		x = 0;
		while (x < SIDE_LEN)
		{
			mlx_pixel_put(mlx->connect, mlx->window, x, y, color);
			x++;
		}
		y++;
	}
}

int	handle_input(int keysym, t_data *mlx)
{
	if (keysym == XK_Escape)
	{
		ft_printf("Escape key %?32d has been pressed\n", keysym);
		close_window(mlx);
		exit (1);
	}
	if (keysym == XK_r)
		color_screen(mlx, encode_rgb(255, 0, 0));
	if (keysym == XK_g)
		color_screen(mlx, encode_rgb(0, 255, 0));
	if (keysym == XK_b)
		color_screen(mlx, encode_rgb(0, 0, 255));
	ft_printf("Key %?33d has been pressed\n", keysym);
	ft_printf("hey before\n");
	mlx_put_image_to_window(mlx->connect, mlx->window, mlx->img.image, 20, 50);
	ft_printf("hey after\n");
	return (0);
}

void	close_window(t_data *mlx)
{
	mlx_clear_window(mlx->connect, mlx->window);
	mlx_destroy_window(mlx->connect, mlx->window);
	mlx_destroy_display(mlx->connect);
	free(mlx->connect);
}

void	open_window(t_data *mlx)
{
	mlx->connect = mlx_init();
	if (mlx->connect == NULL)
		exit (1);
	((t_xvar *)(mlx->connect))->win_list = mlx_new_window(mlx->connect, WIDTH, HEIGHT, "Et le nom");
	if (((t_xvar *)(mlx->connect))->win_list == NULL)
	{
		mlx_destroy_display(mlx->connect);
		free(mlx->connect);
		exit (1);
	}
}

int	main(void)
{
	t_data	mlx;
	int		endian;

	endian = 1;
	open_window(&mlx);
	mlx_key_hook(mlx.window, &handle_input, &mlx);
	//mlx_pixel_put(mlx.connect, mlx.window, 20, 20, 0x05FFFFFF);
	mlx.img.image = mlx_new_image(mlx.connect, WIDTH, HEIGHT);
	mlx_get_data_addr(mlx.img.image, &mlx.img.bpp, &mlx.img.size_line, &endian);
	ft_printf("mlx.img.image = %p | mlx.img.bpp = %d | mlx.img.size_line = %d | mlx.img.format = %d\n", mlx.img.image, mlx.img.bpp, mlx.img.size_line, mlx.img.format);
	mlx_loop(mlx.connect);
	close_window(&mlx);
	return (0);
}
