/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:15:06 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/20 08:16:12 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 || s2[i] != 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else
			i++;
	}
	return (0);
}
// 확실히 열리는지 모를 때, 그리고 오픈을 하고 file discruptor를 넘길 때

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
// 확실히 열리는 걸 알 때, 그리고 오픈을 하지 않고 넘길 때 사용

int	_sizecheck(char *filepath)
{
	int		fd;
	int		count;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * 3);
	fd = open(filepath, O_RDONLY);
	count = 0;
	while (read(fd, buf, 1) == 1)
	{
		++count;
	}
	free(buf);
	return (count);
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

void	_printerrno(char *str1, char *str2)
{
	_printstr(str1);
	_printstr(": ");
	_printstr(str2);
	_printstr(": ");
	_printstr(strerror(errno));
	_printstr("\n");
}
