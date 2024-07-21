/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjuki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:40:38 by yeonjuki          #+#    #+#             */
/*   Updated: 2024/07/10 19:45:50 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush01.h"

void	init_grid(int *grid)
{
	int	i;

	i = 0;
	while (i < 16)
		grid[i++] = 0;
}

void	move_idx(int *row, int *col, int direction)
{
	int	directions[4][4];

	directions[0][0] = 1;
	directions[0][1] = 0;
	directions[1][0] = -1;
	directions[1][1] = 0;
	directions[2][0] = 0;
	directions[2][1] = 1;
	directions[3][0] = 0;
	directions[3][1] = -1;
	*row += directions[direction][0];
	*col += directions[direction][1];
}

void	fill_hint(int *board, int hint, int hint_type, int hint_idx)
{
	int	k;
	int	row;
	int	col;

	if (hint == 1 || hint == 4)
	{
		if (hint_type == 0 || hint_type == 1)
		{
			row = hint_type * 3;
			col = hint_idx;
		}
		else if (hint_type == 2 || hint_type == 3)
		{
			row = hint_idx;
			col = (hint_type % 2) * 3;
		}
		k = (hint % 4) * 3;
		while (k < 4)
		{
			board[row * 4 + col] = k + 1;
			k++;
			move_idx(&row, &col, hint_type);
		}
	}
}

int	read_hint(int *hint_ptr, int *board)
{
	int	hint[4][4];
	int	i;
	int	j;

	i = 0;
	while (i < 16)
	{
		hint[i / 4][i % 4] = hint_ptr[i];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			fill_hint(board, hint[i][j], i, j);
			j++;
		}
		i++;
	}
	return (0);
}
