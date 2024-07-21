/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:59:01 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/20 08:13:41 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	calc_totalsize(int argc, char *argv[])
{
	int	i;
	int	fd;
	int	size;

	i = 0;
	size = 0;
	while (++i < argc)
	{
		if (ft_strcmp(argv[i], "-C"))
		{
			if (argv_open(&fd, argv, i))
				;
			else
				size += sizecheck(&fd);
		}
	}
	return (size);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		fd;
	int		size;
	char	*buffer;
	char	*temp;
	int		index;

	i = 0;
	index = 0;
	size = calc_totalsize(argc, argv);
	buffer = (char *)malloc(sizeof(char) * size);
	while (++i < argc)
	{
		if (ft_strcmp(argv[i], "-C"))
		{
			if (argv_open(&fd, argv, i))
				;
			else
			{
				temp = (char *)malloc(_sizecheck(argv[i]));
				read(fd, temp, _sizecheck(argv[i]));
				index = ft_strcpy(buffer, temp, index);
				free(temp);
			}
		}
	}
	ft_print_memory((void *)buffer, size);
}
