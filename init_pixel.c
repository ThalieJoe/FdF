/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:51:50 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/19 14:06:05 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Allocate memory for pixel structure
*/
t_px	*init_pixel(void)
{
	t_px	*pixel;

	pixel = (t_px *)malloc(sizeof(t_px));
	if (pixel == NULL)
		return (NULL);
	return (pixel);
}
