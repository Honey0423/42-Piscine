/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:28:02 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/19 15:12:08 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int	g_inputbytes;
int	g_readbytes;
int	g_size;

int	argv_open(int *fd, char *argv[], int i)
{
	*fd = open(argv[i], O_RDONLY);
	if (*fd == -1)
	{
		_printerrno(argv[0], argv[i]);
		return (1);
	}
	return (0);
}

int	sizecheck(int *fd)
{
	int		count;
	char	*buf;

	count = 0;
	buf = (char *)malloc(sizeof(char) * 3);
	while (read(*fd, buf, 1) == 1)
	{
		++count;
	}
	free(buf);
	return (count);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		i;
	int		j;
	char	*buf;

	i = 0;
	g_inputbytes = ft_atoi(argv[argc - 1]);
	buf = (char *)malloc(sizeof(char) * g_inputbytes);
	while (++i < argc - 2)
	{
		argv_open(&fd, argv, i);
		if (fd != -1)
		{
			g_size = sizecheck(&fd);
			argv_open(&fd, argv, i);
			j = -1;
			while (++j < g_size - g_inputbytes)
				read(fd, buf, 1);
			g_readbytes = read(fd, buf, g_inputbytes);
			buf[g_readbytes] = '\0';
			_printargs(buf, argv, argc, i);
			close(fd);
		}
	}
}
