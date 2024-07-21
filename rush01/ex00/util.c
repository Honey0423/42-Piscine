/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangpark <sangpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:44:46 by sangpark          #+#    #+#             */
/*   Updated: 2024/07/10 19:49:36 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush01.h"

void	_putchar(char c)
{
	write(1, &c, 1);
}

void	print_result(int *result)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i % 4 == 0 && i != 0)
			_putchar('\n');
		_putchar (result[i] + '0');
		if ((i + 1) % 4 != 0)
			_putchar (' ');
		i++;
	}
	_putchar('\n');
}
