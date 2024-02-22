/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:56:15 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/21 13:23:55 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_file_ext(char *str)
{
	size_t	len;
	char	*trim;

	trim = ft_strtrim(str, "\t\n\v\f ");
	len = ft_strlen(trim);
	if (ft_strcmp(trim + (len - 4), ".fdf") != 0)
	{
		free (trim);
		ft_putendl_fd("WRONG EXT", 2);
		exit (1);
	}
	free (trim);
}
