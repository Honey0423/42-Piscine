/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:17:39 by gahkim            #+#    #+#             */
/*   Updated: 2024/07/03 09:34:27 by kybaek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a);

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (x < 1 || y < 1)
		return ;
	while (i < y)
	{
		while (j < x)
		{
			if (i == 0 && j == 0 || i == y - 1 && j == x - 1)
				ft_putchar('A');
			else if (i == 0 && j == x - 1 || i == y - 1 && j == 0)
				ft_putchar('C');
			else if (i != 0 && i != y - 1 && j != 0 && j != x - 1)
				ft_putchar(' ');
			else
				ft_putchar('B');
			j += 1;
		}
		j = 0;
		i += 1;
		ft_putchar('\n');
	}
}
