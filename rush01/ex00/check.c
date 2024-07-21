/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangpark <sangpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:45:09 by sangpark          #+#    #+#             */
/*   Updated: 2024/07/10 19:30:33 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush01.h"

int	check_main(int *buffer, int *input, int i)
{
	while (++i < 16)
	{
		if (i < 4)
		{
			if (!check_1(buffer, i, input))
				return (0);
		}
		else if (i >= 4 && i < 8)
		{
			if (!check_2(buffer, i - 4, input))
				return (0);
		}
		else if (i >= 8 && i < 12)
		{
			if (!check_3(buffer, i - 8, input))
				return (0);
		}
		else
		{
			if (!check_4(buffer, i - 12, input))
				return (0);
		}
	}
	print_result(buffer);
	return (1);
}

int	check_1(int *buffer, int index, int *input)
{
	int	i;
	int	num;
	int	highest;

	i = 0;
	num = 0;
	highest = 0;
	while (i < 4)
	{
		if (buffer[i * 4 + index] > highest)
		{
			num++;
			highest = buffer[i * 4 + index];
		}
		i++;
	}
	if (input[index] == num)
		return (1);
	return (0);
}

int	check_2(int *buffer, int index, int *input)
{
	int	i;
	int	num;
	int	highest;

	i = 0;
	num = 0;
	highest = 0;
	while (i < 4)
	{
		if (buffer[(3 - i) * 4 + index] > highest)
		{
			num++;
			highest = buffer[(3 - i) * 4 + index];
		}
		i++;
	}
	if (input[index + 4] == num)
		return (1);
	return (0);
}

int	check_3(int *buffer, int index, int *input)
{
	int	i;
	int	num;
	int	highest;

	i = 0;
	num = 0;
	highest = 0;
	while (i < 4)
	{
		if (buffer[index * 4 + i] > highest)
		{
			num++;
			highest = buffer[index * 4 + i];
		}
		i++;
	}
	if (input[index + 8] == num)
		return (1);
	return (0);
}

int	check_4(int *buffer, int index, int *input)
{
	int	i;
	int	num;
	int	highest;

	i = 0;
	num = 0;
	highest = 0;
	while (i < 4)
	{
		if (buffer[index * 4 + 3 - i] > highest)
		{
			num++;
			highest = buffer[index * 4 + 3 - i];
		}
		i++;
	}
	if (input[index + 12] == num)
		return (1);
	return (0);
}
