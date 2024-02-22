/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:28:30 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/20 15:29:03 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	infos_init(t_file *infos)
{
	infos->lines = 0;
	infos->elems = 0;
	infos->size = 0;
	infos->height = 0;
	infos->depth = 0;
	infos->scales[0] = 50;
	infos->scales[1] = 50;
	infos->scales[2] = 50;
	infos->win_margin = 10;
}
