/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:28:30 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/23 15:15:32 by stouitou         ###   ########.fr       */
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
	infos->scales[0] = 100;
	infos->scales[1] = 100;
	infos->scales[2] = 100;
	infos->win_margin = 10;
}
