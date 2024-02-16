/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_ext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:56:15 by stouitou          #+#    #+#             */
/*   Updated: 2024/02/15 16:07:34 by stouitou         ###   ########.fr       */
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
		ft_printf("WRONG EXT\n");
		exit (1);
	}
	ft_printf("OK EXT\n");
	free (trim);
}
