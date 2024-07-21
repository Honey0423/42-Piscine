/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 01:36:22 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/09 02:09:08 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	to_hex(int num)
{
	char	*hex;

	hex = "0123456789abcdef";
	return (hex[num]);
}

void	print_addr(unsigned long long addr)
{
	char	result[16];
	int		i;

	i = 0;
	while (i < 16)
	{
		result[i++] = to_hex(addr % 16);
		addr /= 16;
	}
	while (i > 0)
		write(1, &result[--i], 1);
	write(1, ": ", 2);
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
		if (i % 4 == 0)
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
	if (len >= 16)
		write(1, result, 16);
	else
		write(1, result, len);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	char			*str;

	str = (char *)addr;
	i = 0;
	while (i < size)
	{
		print_addr((unsigned long long)&str[i]);
		print_hex((unsigned char *)&str[i], size - i);
		print_word((unsigned char *)&str[i], size - i);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
