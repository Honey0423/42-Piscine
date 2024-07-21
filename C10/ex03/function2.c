/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:53:47 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/20 07:24:50 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	_printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		++i;
	}
}

int	ft_strcpy(char *str1, char *str2, int index)
{
	int	j;

	j = 0;
	while (str2[j] != 0)
	{
		str1[index + j] = str2[j];
		++j;
	}
	return (index + j);
}
