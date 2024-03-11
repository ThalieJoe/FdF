/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:32:59 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/11 16:30:48 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_and_exit(t_xvar *connect, int err)
{
	if (connect != NULL)
	{
		mlx_destroy_display(connect);
		free(connect);
	}
	if (err)
		exit (EXIT_FAILURE);
}
