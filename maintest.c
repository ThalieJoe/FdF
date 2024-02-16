/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:17:21 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/15 17:29:45 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_ligne
{
	char *str;
	int number_lines;
	void *mlx_ptr;
	void *mlx_win;
}	t_ligne;

int handle_keypress(int code, t_ligne *ligne)
{
	printf("Key : %d\n", code);
	return(0);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *str = "Je suis un chat";
	t_ligne ligne;
	int err;
	ligne.mlx_ptr = mlx_init();
	if(!ligne.mlx_ptr)
		return(1);
	ligne.mlx_win = mlx_new_window(ligne.mlx_ptr, 100, 100, "chat");
	mlx_hook(ligne.mlx_win, KeyPress, KeyPressMask, &handle_keypress, &ligne);
	mlx_destroy_window( ligne.mlx_ptr,ligne.mlx_win);
	return(0);
}
