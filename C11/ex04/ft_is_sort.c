/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeum <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:26:41 by dgeum             #+#    #+#             */
/*   Updated: 2024/07/19 23:54:13 by dgeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	ascend;
	int	descend;
	int	i;
	int	num;

	i = 0;
	ascend = 1;
	descend = 1;
	while (i < length - 1)
	{
		num = f(tab[i], tab[i + 1]);
		if (num < 0)
			descend = 0;
		else if (num > 0)
			ascend = 0;
		++i;
	}
	return (ascend | descend);
}
