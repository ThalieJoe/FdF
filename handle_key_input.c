/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:37:24 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/20 15:37:38 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
