/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:28:05 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/11 22:57:12 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	jump(char *str, int i, int *sign)
{
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

int	find_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	base_check(char *base, int i, int j, int len)
{
	while (base[len] != '\0')
		len++;
	if (len < 2)
		return (1);
	while (base[i] != 0)
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (1);
		if (base[i] == ' ' || base[i] == '\n' || base[i] == '\t' || \
base[i] == '\v' || base[i] == '\f' || base[i] == '\r')
			return (1);
		while (j < len)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	index;
	int	num;
	int	sign;
	int	len;

	if (base_check(base, 0, 0, 0))
		return (0);
	sign = 1;
	i = jump(str, 0, &sign);
	num = 0;
	len = _strlen(base);
	while (str[i] != '\0')
	{
		index = find_in_base(str[i], base);
		if (index >= 0)
			num = num * len + index;
		else
			return (0);
		i++;
	}
	return (sign * num);
}
