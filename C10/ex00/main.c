/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:09:13 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/16 10:25:25 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc == 1)
	{
		write(1, "File name missing.\n", 20);
		return (1);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 21);
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "Cannot read file.\n", 19);
		return (1);
	}
}
