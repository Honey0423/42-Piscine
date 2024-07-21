/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:36:22 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/20 08:59:33 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	to_hex(int num)
{
	char	*hex;

	hex = "0123456789abcdef";
	return (hex[num]);
}

void	print_addr(unsigned int addr)
{
	char	result[8];
	int		i;

	i = 0;
	while (i < 8)
	{
		result[i++] = to_hex(addr % 16);
		addr /= 16;
	}
	while (i > 0)
		write(1, &result[--i], 1);
	write(1, "  ", 2);
}

void	print_hex(unsigned char *str, int len)
{
	int		i;
	char	result[32];

	i = 0;
	while (i < 32)
		result[i++] = ' ';
	i = 0;
	while (i < 16 && i < len)
	{
		result[2 * i] = to_hex(str[i] / 16);
		result[2 * i + 1] = to_hex(str[i] % 16);
		i++;
	}
	i = 0;
	while (i < 32)
	{
		write(1, &result[i++], 1);
		if (i % 2 == 0)
			write(1, " ", 1);
		if (i % 16 == 0)
			write(1, " ", 1);
	}
}

void	print_word(unsigned char *str, int len)
{
	int		i;
	char	result[16];

	i = 0;
	while (i < 16)
		result[i++] = ' ';
	i = 0;
	while (i < 16 && i < len)
	{
		if (str[i] >= 32 && str[i] <= 126)
			result[i] = str[i];
		else
			result[i] = '.';
		i++;
	}
	write(1, "|", 1);
	if (len >= 16)
		write(1, result, 16);
	else
		write(1, result, len);
	write(1, "|", 1);
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	address;
	unsigned int	i;
	unsigned char	*str;

	str = (unsigned char *)addr;
	address = 0;
	i = 0;
	while (i < size)
	{
		if (check(&str[i], &str[i - 16], size - i, size - i + 16))
		{
			print_addr(address + i);
			print_hex(&str[i], size - i);
			print_word(&str[i], size - i);
			write(1, "\n", 1);
		}
		else
			write(1, "*\n", 2);
		i += 16;
	}
	print_addr(address + size);
	write(1, "\n", 1);
}
