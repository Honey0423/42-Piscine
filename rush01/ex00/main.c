/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:16:38 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/10 19:50:14 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush01.h"

int	main(int argc, char *argv[])
{
	int	input[16];
	int	grid[16];
	int	flag;

	if (argc != 2 || !arg_validation(argv[1]))
	{	
		write(1, "Error\n", 6);
		return (1);
	}
	if (!parse_args(input, argv[1], ft_strlen(argv[1])))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	init_grid(grid);
	flag = 0;
	read_hint(input, grid);
	find_all_solutions(grid, 0, &flag, input);
	if (flag == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
