/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 23:55:01 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/20 09:46:40 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	_operator(char *str)
{
	int	i;

	i = 0;
	while (str[i++] != 0)
		;
	if (i > 2)
		return (0);
	if (str[0] == '+')
		return (1);
	else if (str[0] == '-')
		return (2);
	else if (str[0] == '*')
		return (3);
	else if (str[0] == '/')
		return (4);
	else if (str[0] == '%')
		return (5);
	else
		return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int input)
{
	long long	num;

	num = (long long) input;
	if (num < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-num);
	}
	else if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putchar('0' + num % 10);
	}
	else
		ft_putchar('0' + num);
}

int	main(int argc, char *argv[])
{
	int	oper;

	if (argc != 4)
		return (1);
	oper = _operator(argv[2]);
	if (oper == 1)
		ft_putnbr(ft_atoi(argv[1]) + ft_atoi(argv[3]));
	else if (oper == 2)
		ft_putnbr(ft_atoi(argv[1]) - ft_atoi(argv[3]));
	else if (oper == 3)
		ft_putnbr(ft_atoi(argv[1]) * ft_atoi(argv[3]));
	else if (oper == 4)
		division(ft_atoi(argv[1]), ft_atoi(argv[3]), 1);
	else if (oper == 5)
		division(ft_atoi(argv[1]), ft_atoi(argv[3]), 2);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
