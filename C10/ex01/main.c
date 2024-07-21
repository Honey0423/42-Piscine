/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:28:02 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/17 00:43:30 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

void	_printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		++i;
	}
}

void	_printerrno(char *str1, char *str2)
{
	_printstr(str1);
	_printstr(": ");
	_printstr(str2);
	_printstr(": ");
	_printstr(strerror(errno));
	_printstr("\n");
}

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

int	main(int argc, char *argv[])
{
	int		fd;
	int		i;
	char	buf[30 * 1024];
	int		readbytes;

	i = 1;
	while (i < argc)
	{
		argv_open(&fd, argv, i);
		if (fd != -1)
		{
			readbytes = read(fd, (char *)&buf, 30 * 1024);
			buf[readbytes] = '\0';
			_printstr(buf);
			close(fd);
			if (fd == -1)
				_printerrno(argv[0], argv[i]);
		}
		++i;
	}
	if (argc == 1)
		argv_open(&fd, argv, i);
}
