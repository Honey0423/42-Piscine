/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:29:00 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/11 01:39:45 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
