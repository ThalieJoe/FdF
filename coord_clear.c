/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:54:27 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/15 14:16:14 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	coord_clear(t_coord **coord)
{
	t_coord	*head;
	t_coord	*prev;

	if (coord == NULL)
		return ;
	head = (*coord)->head;
	while (head)
	{
		prev = head->prev;
		free(head->px);
		free(head);
		head = prev;
	}
	*coord = NULL;
}
