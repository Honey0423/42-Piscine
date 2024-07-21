/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 06:38:48 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/17 05:27:26 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long long	num;

	num = (long long) nb;
	if (num < 0)
	{
		num *= -1;
		_putchar('-');
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	_putchar(num % 10 + '0');
}

void	_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		++i;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		_print_str(par[i].str);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		_print_str(par[i].copy);
		++i;
	}
}
