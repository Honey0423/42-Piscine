/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 04:02:28 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/17 04:32:39 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

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

void	_printargs(char *str, char *files[], int argc, int index)
{
	int	i;

	i = 0;
	if (argc > 4)
	{
		if (index != 1)
			write(1, "\n",1);
		write(1, "==> ", 4);
		while (files[index][i] != 0)
		{
			write(1, &files[index][i++], 1);
		}
		write(1, " <==\n", 5);
	}
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
	_printstr("cannot open '");
	_printstr(str2);
	_printstr("' for reading");
	_printstr(": ");
	_printstr(strerror(errno));
	_printstr("\n");
}
