/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:07:00 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/10 19:29:57 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush01.h"

int	is_valid(int *grid, int index, int num)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		if (grid[(index / 4) * 4 + x] == num)
			return (0);
		if (grid[x * 4 + index % 4] == num)
			return (0);
		x++;
	}
	return (1);
}

void	find_all_solutions(int *grid, int index, int *flag, int *input)
{
	int	num;

	num = 1;
	if (*flag == 1)
		return ;
	if (index >= 16)
	{
		*flag = check_main(grid, input, -1);
		return ;
	}
	if (grid[index])
		find_all_solutions(grid, index + 1, flag, input);
	while (num <= 4)
	{
		if (is_valid(grid, index, num))
		{
			grid[index] = num;
			find_all_solutions(grid, index + 1, flag, input);
			grid[index] = 0;
		}
		num++;
	}
}
