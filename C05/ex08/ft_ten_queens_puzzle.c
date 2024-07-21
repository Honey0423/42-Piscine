/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 02:36:54 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/12 03:07:31 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_r[10];
int	g_cnt;

void	_putchar(char c)
{
	write(1, &c, 1);
}

void	print(void)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		_putchar('0' + g_r[i]);
		i++;
	}
	write(1, "\n", 1);
	g_cnt++;
}

void	nqueen(int col, int i, int flag)
{
	int	j;

	if (col == 10)
	{
		print();
		return ;
	}
	while (i < 10)
	{
		j = 0;
		flag = 1;
		while (j < col && flag)
		{
			g_r[col] = i;
			if (g_r[j] == g_r[col] || ((j - col) == (g_r[j] - \
g_r[col])) || ((j - col) == (g_r[col] - g_r[j])))
				flag = 0;
			j++;
		}
		if (flag)
			nqueen(col + 1, 0, 0);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	i;

	i = 0;
	g_cnt = 0;
	while (i < 10)
	{
		g_r[0] = i;
		nqueen(1, 0, 1);
		i++;
	}
	return (g_cnt);
}
