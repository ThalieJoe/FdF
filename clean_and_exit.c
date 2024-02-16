/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:32:59 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/15 16:13:07 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_and_exit(t_xvar **connect, t_img **img)
{
	mlx_destroy_image(*connect, *img);
	mlx_destroy_display(*connect);
	free(*connect);
}
