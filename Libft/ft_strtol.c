/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:57:19 by stouitou          #+#    #+#             */
/*   Updated: 2024/03/06 10:29:22 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*str;
	long	res;

	str = "0XFFFFFF";
	res = strtol(str, NULL, 16);
	printf("res = %ld\n", res);
}
