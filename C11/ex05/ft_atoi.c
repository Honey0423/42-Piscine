/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:28:05 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/21 17:29:33 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	i = jump(str, 0, &sign);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	division(int num1, int num2, int oper)
{
	if (num2 == 0)
	{
		if (oper == 1)
			write(1, "Stop : division by zero", 23);
		else
			write(1, "Stop : modulo by zero", 21);
	}
	else if (oper == 1)
		ft_putnbr(num1 / num2);
	else
		ft_putnbr(num1 % num2);
}
