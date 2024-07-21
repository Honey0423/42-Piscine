/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 01:39:30 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/11 21:25:03 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	_print(long long nbr, char *base, long long len)
{
	char	c;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= len)
	{
		_print(nbr / len, base, len);
	}
	c = base[nbr % len];
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			i;
	int			j;
	long long	len;
	long long	num;

	i = -1;
	len = 0;
	num = (long long) nbr;
	while (base[len] != '\0')
		len++;
	if (len < 2)
		return ;
	while (base[++i] != 0)
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return ;
		while (j < len)
		{
			if (base[i] == base[j])
				return ;
			j++;
		}
	}
	_print(num, base, len);
}
