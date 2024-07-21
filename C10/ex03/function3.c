/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 08:10:35 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/20 10:00:14 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check(unsigned char *str1, unsigned char *str2, int len1, int len2)
{
	int	i;

	i = 0;
	if (len1 != len2)
		return (1);
	else
	{
		while (i < 16 && i < len1)
		{
			if (str1[i] != str2[i])
				return (1);
			++i;
		}
	}
	return (0);
}

int	pass_equaldata(unsigned char *str, int index, int len)
{
	
}
