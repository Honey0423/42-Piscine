/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 00:11:47 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/05 21:22:55 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	_putchar(char c)
{
	write(1, &c, 1);
}

void	_print(int *buf, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		_putchar(buf[i] + '0');
		i++;
	}
	if (buf[0] != 10 - n)
		write(1, ", ", 2);
}

void	combn(int index, int n, int *buf)
{
	if (index == n - 1)
	{
		if (buf[index] > (10 - n + index))
			return ;
		while (buf[index] <= (10 - n + index))
		{	
			_print(buf, n);
			buf[index]++;
		}
	}
	else
	{
		while (buf[index] <= (10 - n + index))
		{
			buf[index + 1] = buf[index] + 1;
			combn(index + 1, n, buf);
			buf[index]++;
		}
	}
}

void	ft_print_combn(int n)
{
	int	i;
	int	num;
	int	buf[10];

	i = 0;
	num = 0;
	if (n < 0 || n > 10)
		return ;
	while (i < n)
	{
		buf[i] = i;
		i++;
	}
	combn(0, n, buf);
}
