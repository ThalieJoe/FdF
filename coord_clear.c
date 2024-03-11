/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:54:27 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/11 17:11:34 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	coord_clear(t_coord **coord)
{
	t_coord	*next;

	if (coord == NULL)
		return ;
	while (*coord)
	{
		next = (*coord)->next;
		free((*coord)->px);
		free(*coord);
		*coord = next;
	}
	*coord = NULL;
}
